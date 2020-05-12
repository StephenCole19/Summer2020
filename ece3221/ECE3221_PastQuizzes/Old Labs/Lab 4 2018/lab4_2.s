#Lab 4
#Thales Santos and Alexis Savoie
#NOTE: LCD DISPLAY IS NOT WORKING CORRECTLY

.equ timer,0x8870
.equ hexcontrolreg, 0x88B0

# Introductory comments required here
# .equ directives required here
.global _start

# ------------------
# Macro operations for push and pop

# Push
.macro push  rx
       addi  sp, sp, -4
       stw  \rx, 0(sp)
.endm

# Pop
.macro pop  rx
      ldw   \rx, 0(sp)
      addi  sp, sp, 4
.endm

# ==========================================
# interrupt service routine (ISR)
.org 0x0020 # this code lies at address 20

	#Pushing registers
	push r3
	
	push r4
	
	push ra
	
	push r5
	
	push r6
	
	push r7
	# determine source of interrupt
	# ------------------------------------
	# was it the timer input port?
	rdctl r3,ipending # r3 = pending interrupt bits
	
	andi r4,r3,0b00000100 # r3 = pending int2 bit
	
	beq r4,r0,endCode # ignore if not int2

	call clocker #calling clocker
	
    ori   r5, r0, pattern # storing the address for pattern
	
    ori   r6, r0, 0x8880 # Adress of LEDS
	
    ldw   r7, (r5) # Loading pattern values to r7
	
    stw   r7, (r6) # Writting the pattern to the LEDS
	
    srli  r7, r7, 0X01 # Shifting left by 1
	
    bne   r7, r0, finish # Navigate to finish once all LEDS have been lit up
	
    addi  r7, r0, 0x200 #Return to first LED

finish:
    stw r7, (r5) #Restart 

	#Resting the timer to zero
	ori r4,r0,timer
	stwio r3,12(r4)
# ------------------------------------
endCode:

	#Popping registers
	pop r7
	
	pop r6
	
	pop r5
	
	pop ra
	
	pop r4
	
	pop r3
	
	addi ea,ea,-4
	
	eret #return
# ==========================================

# ==========================================
# main program starts here (after the ISR)
# ------------------------------------------
_start:
call init

	#Attempting to clear LCD Display and write to the display
    ori r8, r0, 0x701
	
    call outchr
	
    ori r4, r0, mystring
    
	call outstr


here:

	#Displaying time on Hex Display
	
    ori r2, r0, 0x88A0 #Storing address of seven segment displays
	
    ori r3, r0, time #Storing value of the time

    ldw r5, (r3) #Loading value of the time into r5  
	
    andi r6, r5, 0x0f #Masking bits
	
    srli r5, r5, 0x04 #Shifts bits by 4

	#Setting values and isolating certain bits

    andi r7, r5, 0xf0
	
    or   r6, r6, r7
	
    srli r5, r5, 4
	
    andi r7, r5, 0xf00
	
    or   r6, r6, r7
	
    srli r5, r5, 4

    andi r7, r5, 0xf000
	
    or   r6, r6, r7

	#Attemping to display time on LCD display 
    sth r6, (r2)
	
    call show4
	
    br here      
# ==========================================

# ==========================================
# subroutines start here
# ------------------------------------------
init:
	ori sp,r0,stacktop # set stack pointer
	# enable four hex digits
	ori r6,r0,0x010f
	ori r5,r0,hexcontrolreg
	 sthio r6,0(r5)
# SETUP INTERRUPTS IN THREE STEPS 1,2,3
# (1) enable timer interrupt on 10 Hz edge
	ori r22,r0,timer
	ori r3,r0,0b00010000 # select 10 Hz output
	stbio r3,8(r22)
# (2) enable int2 (decade timer) in processor
	rdctl r3,ienable
	ori r3,r3,0x00000004 # int2 = bit 2 = 1
	wrctl ienable,r3
# (3) turn on master interrupt enable
	rdctl r3,status
	ori r3,r3,0x01 # PIE bit = 1
	wrctl status ,r3
	ret
# ------------------------------------------
# ------------------------------------------
#=======================================================
#clocker:
#Increment the four digit BCD time stored in time label
#No registers affected
clocker:

	#Pushing registers
    push r1
	
    push r2
	
    push r3
	
    push r4
	
    push r5
	
    push r6
	
    push r7
	
	
    ori r1, r0, time #storing value of the time
	
    ldb r2, 0(r1) #Hex display showing the msecs 
	
    ldb r3, 1(r1) #Hex display showing seconds
	
    ldb r4, 2(r1) #Hex display showing seconds
	
    ldb r5, 3(r1) #Hex display showing minutes

    ori r7, r0, 10	# Storing a value as 10 to reference to later
	
    ori r6, r0, 6 #Storing a value of 6 to reference to when the seconds in the 10 place get to 6
	
    addi r2, r2, 0X01 #Incrementing the time
	
    bne r2, r7, notMax #If r2 does not equal 10 branch to notMax function

	#msec
    ori r2, r0, 0
	
    addi r3, r3, 1
	
    bne r3, r7, notMax       

	#seconds
    ori r3, r0, 0
	
    addi r4, r4, 1
	
    bne r4, r6, notMax 

	#minutes
    ori r4, r0, 0
	
    addi r5, r5, 1 
	
    bne r5, r7, notMax

# Load back in
    ldb r2, 0(r1)
	
    ldb r3, 1(r1)
	
    ldb r4, 2(r1)
	
    ldb r5, 3(r1)

notMax:
# Store value back in and Pop off stack
    stb r2, 0(r1)
    stb r3, 1(r1)
    stb r4, 2(r1)
    stb r5, 3(r1)
	
	#Popping registers
    pop r7
	
    pop r6
	
    pop r5
	
    pop r4
	
    pop r3
	
    pop r2
	
    pop r1
	
    ret


#=======================================================
#=======================================================
#outstr:
#Display a string to the LCD display
#No registers affected	
outstr:
	push r1
	
	push r3
	
	ori r1,r0, 0x88C0 #Address of LCD
	
	call delay
	
	addi r3, r3, 1 #incrementing by 1
	
	call outchr
	
	bne r3, r0, outstr
	
	pop r3
	pop r1
	
#=======================================================
#outchr:
#Display a char to the LCD display
#No registers affected		
outchr:
	push r1

	ori r1, r0, 0x88C0 #Address of LCD
	
	stw r3, 0(r1) #Storing char to the display
	
	call delay
	
	pop r1
	
#=======================================================
#delay Subroutine (From previous lab):
#Authors: Raymond Laks, Drew Graham    Date: May,31, 2018
#Used to wait N seconds (maximum 10), where N is value in r3
#Input Registers: r3
#Output Registers: none
#Registers Affected: none


delay: 
  push r10
  push r5
  push r6
  push r7
  
  ori r10,r0,0x8870 # r10 = address of timer
  or r5,r3,r0 # number of ms from r3
  ori r7,r0,10000 # max 10 sec
  
  # count in ms
  loop1:   
  ldbio r6,0(r10)
  andi r6,r6,4
  beq r6,r0,loop1
  loop2:
  ldbio r6,0(r10)
  andi r6,r6,4
  bne r6,r0,loop2
  
  addi r5,r5,-1
  addi r7,r7,-1
  beq r7,r0,done2 # end if 10 sec counted
  bne r5,r0,loop1 
  
  done2:
  
  pop r7
  pop r6
  pop r5
  pop r10
  
  ret

# end delay

# ------------------------------------------
#======================================================
#=======================================================
#show4:
#Send the time to the LCD display
#No registers affected

show4:
	#Push registers
    push r4
	
    push r5  
	
    push r6
	
    push ra

# Display minute amd Display seconds 

    ori r4, r0, time #Storing value of time
	
    ldb r5, 3(r4) #Loading value of time into r5
	
    ori r5, r5, 0x030 #Masking  
	
	#Attempting to write to LCD display and display the minutes
    call outchr
	
    andi r5, r0, 0      
    
    ori r5, r0,'m'
	
    call outchr

    ldb r5, 2(r4)   
	
    ori r5, r5, 0x30  
	
    call outchr
	
    ldb r5, 1(r4)   
	
    ori r5, r5, 0x30  
    
    call outchr
	
    andi r5, r0, 0   
	
    ori r5, r0,'.'
	
    call outchr           

	#Attempting to write to LCD display and display the msecs
    ldb r5, 0(r4)   
	
    ori r5, r5, 0x30    
	
    call outchr
	
    andi r5, r0, 0      
	
    ori r5, r0,'s'
	
    call outchr
	
	#Popping registers
    pop ra
	
    pop r6
	
    pop r5
	
    pop r4
	
    ret

# ==========================================
# data storage starts here
# reserve 400 bytes = 100 words for stack
.skip 400
stacktop:
# ------------------------------------------
# four digits for the time stored in BCD format
time: .byte 0,0,0,0
pattern: .word 0 # display LED state

# string to be displayed on Line 1
# may be modified (maximum 16 characters)

mystring: .asciz "TIME SINCE START"
# ------------------------------------------
.end
