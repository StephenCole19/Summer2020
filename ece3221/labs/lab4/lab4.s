.global _start
_start: br Start

# Macros
#------------------------------------------------------------------
.macro push rx
	addi sp ,sp ,-4
	stw \rx ,0(sp)
.endm

.macro pop rx
	ldw \rx ,0(sp)
	addi sp ,sp ,4
.endm
#-------------------------------------------------------------------

# ISR
#-------------------------------------------------------------------
.org 0x0020
	push ra
	push r3
	push r4
	
	# determine source of interrupt
	rdctl r3,ipending # r3 = pending interrupt bits
	andi r4,r3,0x01 # r4 = pending int0 bit
	bne r4,r0,int0 # service int0 if requested
	br endint # done

	# IRQ0 service (interval timer)
int0:
	call action0 # provide a specific response to the timer interrupt
	             # silence the interval timer interrupt request
	movia r4,0x10002000 # r4 = interval timer addr
	sthio r0,(r4) # set TO=0
	br endint # done
	
endint:
	pop r4
	pop r3
	pop ra
	addi ea,ea,-4 # ISR done
	eret
#-------------------------------------------------------------------

#-------------------------------------------------------------------
.org 0x0100
Start:
	movia sp,stacktop # initialize the stack pointer
	call setupInterrupts # initialization
#-------------------------------------------------------------------

# Subroutines
#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Outputs to the terminal window a single ASCII character in r3. 
# Input: r3 
outchar:
	
#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Outputs to the terminal window a null-terminated ASCII string at the address provided in r3. 
# Input: r3 
outstr:

#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Outputs to the terminal window a single ASCII character being the hexadecimal representation of the 4 least significant bits in r3. 
# Input: r3 
outhex:

#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Outputs to the terminal window ASCII ‘0’,‘x’, plus 8 characters being the hexadecimal representation of the 32-bit contents of r3. 
# Input: r3 
outhex32:

#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Outputs to the terminal window up to ten ASCII characters being the decimal representation of the 32-bit contents of r3. Include leading zero-suppression.
# Input: r3 
outint32:

#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Determines if the unsigned integer contents of r3 are a prime number. 
# Returns 1 (true) or 0 (false) in r4.
# Input: r3 
# Output r4
isprime:

#-------------------------------------------------------------------
# Stephen Cole - June 9th
# Clears the 7-segment displays, the green LEDs and the red LEDs. Calls setupInterrupts.
init:

#-------------------------------------------------------------------
# set up for expected interrupts from the interval timer
setupInterrupts:
	push ra
	push r3
	# SETUP INTERRUPTS IN THREE STEPS 1,2,3
	# (1) set up a device to generate interrupts
	call setupTimer # set up interval timer (IRQ0)
	# (2) set up the processor to acknowledge specific interrupt(s)
	rdctl r3,ienable # ienable: enable IRQn by setting Bitn = 1
	ori r3,r3,0x01 # set bit0 = 1 for IRQ0
	wrctl ienable,r3 # update ienable register
	# (3) turn on the processor master interrupt enable
	rdctl r3,status # status: various processor control bits
	ori r3,r3,0x01 # set PIE bit = 1 (Processor Interrupt Enable)
	wrctl status ,r3 # update status register
	pop r3
	pop ra
ret
#-------------------------------------------------------------------
# setupTimer RTervo May 2020
# set up the DE2-115 interval timer
# to generate an interrupt every 0.1 sec
# no registers affected
setupTimer:
	push r3
	push r11
	movia r11,0x10000000 # r11 = I/O base addr
	# the interval counter is clocked at 50 MHz
	# r3 = timing interval (clocks) in decimal
	movia r3,5000000 # let delay = 0.1 sec
	sthio r3,0x2008(r11) # set timer low half word
	srli r3,r3,16 # shift to other 16 bits
	sthio r3,0x200C(r11) # set timer high half word
	sthio r0,0x2000(r11) # TO=0 (clear timeout bit)
	ori r3,r0,0x0007 # START=1, CONT=1, ITO=1
	sthio r3,0x2004(r11)
	pop r11
	pop r3
ret
#-------------------------------------------------------------------


# ALLOCATION
#-------------------------------------------------------------------
.skip 400 # stack = 200 bytes = 50 words
stacktop:
welcome: .asciz " ECE3221 Lab4 \n"
#-------------------------------------------------------------------