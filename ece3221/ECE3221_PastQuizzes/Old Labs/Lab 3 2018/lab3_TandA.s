/* ECE3221 LAB#3 - SUBROUTINES
-----------------------------------------------
DATE: Nov 2015 NAME: R.Tervo
-----------------------------------------------
A Slot Machine
- rapidly display four counting digits
- each digits stops when its button is pressed
- when all stops, four cherries wins
 (any four digits, all the same)
-----------------------------------------------
*/
/** definitions for push and pop macros go here **/
.global _start
.EQU N, 600 # loop delay in msec
.EQU TIMER,0x8870
_start:
	call init # perform initialization
top:
	ori r3,r0,N # wait here for N msec
	call delay
	call buttons # check buttons now
	beq r5,r0,four # done if all digits stopped

digit3:
	ori r22,r0,code # point to first digit
	ori r4,r0,0x08 # select digit 3 mask
	and r3,r4,r5 # check if digit is enabled
	beq r3,r0,digit2 # skip increment if not enabled
	call incx
	
digit2:
	addi r22,r22,0x1 # point to first digit
	ori r4,r0,0x04 # select digit 3 mask
	and r3,r4,r5 # check if digit is enabled
	beq r3,r0,digit1 # skip increment if not enabled
	call incx
	
digit1:
	addi r22,r22,0x1 # point to first digit
	ori r4,r0,0x02 # select digit 3 mask
	and r3,r4,r5 # check if digit is enabled
	beq r3,r0,digit0 # skip increment if not enabled
	call incx
	
	
digit0:
	addi r22,r22,0x1 # point to first digit
	ori r4,r0,0x01 # select digit 3 mask
	and r3,r4,r5 # check if digit is enabled
	beq r3,r0,final # skip increment if not enabled
	call incx
	
final:
	call show4 # update the display
	br top # start over
four:
	call check4 # fireworks if match found
	call switch0 # wait here for edge on SW0
	ori r5,r0,0x0F # re-enable count on all digits
	call reset4 # reset display digit values
br top # start over


#===============================================================
#Thales Santos and Alexis Savoie

#Macros created for push and pop
.macro push rx
	addi sp ,sp ,-4
	stw \rx ,0(sp)
.endm

.macro pop rx
	ldw \rx ,0(sp)
	addi sp ,sp ,4
.endm
#===============================================================
#Thales Santos and Alexis Savoie
#This subroutine initializes the stack pointer and activates the seven segment display
#register sp is initialized at stacktop
#The values are passed to sp with the stacktop, no other registers are affected


init:
	push r3
	push r2
	ori sp,r0,stacktop 	# Initialize the stack pointer
	ori r3,r0,0x88B0 	# R3 = address of HEX control
	ori r2,r0,0x010F 	# R2 = pattern = 4 hex digits ON
	ori r5,r0,0xF		#r5 = 1111
	sthio r2,(r3) 		# initialize hex display
	pop r2
	pop r3


/*
	push r1
	push r2
	
	ori sp, r0, stacktop
	ori r1, r0, 0x88B0
	ori r2, r0, 0x010F
	sthio r2, 0(r1)
	
	pop r2
	pop r1
*/
	ret	
#===============================================================
/*
delay Subroutine:
 Authors: Raymond Laks, Drew Graham    Date: May,31, 2018
 Used to wait N seconds (maximum 10), where N is value in r3
 Input Registers: r3
 Output Registers: none
 Registers Affected: none
*/

delay: push r10
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
#==================================================================
#Thales Santos and Alexis Savoie
#This subroutine checks if a button has been pressed, if so the value of r5 is set to zero
#Register r5 affected
#0 passed into r5 by use of an ori
	
buttons:

	push r1
	push r2
	
	ori r1, r0, 0x8860
	ldbio r2,0(r1)
	and r5, r5, r2
	
	pop r2
	pop r1
	ret

#==================================================================	
#Thales Santos and Alexis Savoie
#This subroutine increments a single digit value stored in byte memory
#No registers are affected
#No values passed
	
	
incx:
	push r3
	 
	ldb r3,(r22)			# Load previous value of r22 to r3. (note r22 is a whole word, 4 bytes)
	addi r3,r3,0x01			# Increment r3.
	andi r3,r3,0xF
	stb r3,(r22)			# Store incremented value of r3 back in r22. (r22 being 4 bytes.) 
	pop r3
	ret
	
#==================================================================	

# Subroutine: show4

# Author: Megan Doherty

# This subroutine displays the four stored digits in the hex display.

# No registers should be affected. Ra, R5, R4 and R3 are all pushed and popped off of the stack.

 

show4:

    push r3                 # Put r3 on stack

    push r4                 # Put r4 on stack

    push r5                 # Put r5 on stack

    push ra                 # Put ra on stack

 

    ori r4,r0,code          # r4 = code

    ldb r5,0(r4)            # r5 = Digit 1

    slli r3,r5,4

    ldb r5,1(r4)            # r5 = Digit 2

    add r3,r3,r5            # r3 = Both digits so far (1 and 2)

    slli r3,r3,4

    ldb r5,2(r4)            # r5 = Digit 3

    add r3,r3,r5            # r3 = All digits so far (1, 2 and 3)

    slli r3,r3,4

    ldb r5,3(r4)            # r5 = Digit 4

    add r3,r3,r5            # r3 = All digits

    call outhex             # write r3 to display

 

    pop ra                  # remove ra

    pop r5                  # remove r5

    pop r4                  # remove r4

    pop r3                  # remove r3

    ret
	
#==================================================================		
# Name: check4
# Author: Adriana Aragon Lopez
# Description: Check if the four stored digits are identical. 
# If they are identical, then call fireworks (below) before returning.
# Registers affected: None

check4:

	push ra 	
	push r3
	push r4
	push r5

	ori r3, r0, code #r3 = address of array code = address of disp digits

	ldb r4, 0(r3) #r4 = value of disp digit 1
	ldb r5, 1(r3) #r5 = value of disp digit 2
	bne r4, r5, end #check next digit if equal
	ldb r5, 2(r3) #r5 = value of disp digit 3
	bne r4, r5, end #check next digit if equal
	ldb r5, 3(r3) #r5 = value of disp digit 4
	bne r4, r5, end #check next digit if equal

	call fireworks

	end: 
	pop r5
	pop r4
	pop r3
	pop ra

	ret

#==================================================================		
#================================================
# Subroutine switch0
# Description: This subroutine waits until SW0 goes up and down.
# Inputs: None
# Outputs: None
# Author: Brooks Conklin
# No registers are affected
/*
switch0:

	push r3
	push r4
	push r5
	push r6

	ori r3,r0,0x8850 # Address of switches
	ori 

check1:
	ldwio r4, 0(r3)
	
	addi r6, r6, -1
	bne r6, r0, check1 
	
	ori r6, r0, 200
	
	beq r4, r5, check2
	br check1
	
check2:
	ldwio r4, 0(r3)
	
	addi r6, r6, -1
	bne r6, r0, check2
	
	ori r6, r0, 200
	
	beq r4, r0, check3
	br check2
	
check3:
	ldwio r4, 0(r3)
	
	addi r6, r6, -1
	bne r6, r0, check3
	
	ori r6, r0, 200
	
	beq r4, r5, done
	br check3

done:
	pop r5
	pop r4
	pop r3

	ret
*/
# Name: Switch0
# Author: Adriana Aragon Lopez
# Description: Wait for an edge on switch SW0.
# Registers affected: None
/*
switch0:

	push r5
	push r6
	push r7
	push r8
	
	ori r5, r0, 0x8850 # r5 = addr of switches
	ori r7, r0, 1
	ori r8, r0, 65000
	
switchtop:

	ldwio r6,0(r5) # r6 = value of switches
	andi r6, r6, 0x1 # isolate switch 0
	
	addi r8, r8, -1
	bne r8,r0,switchtop
	ori r8, r0, 65000
	beq r6, r0, switchmid # if r6 ~= r0 go to switchtop
	bne r6, r0, switchtop

switchmid:
	ldwio r6, 0(r5) # r6 = value of switches
	andi r6, r6, 0x1 # isolate switch 0x1
	
	addi r8, r8, -1
	bne r8,r0,switchmid
	ori r8, r0, 65000
	beq r6, r7, switchfinal # if r6 = 0 go to switch mid
	bne r6, r7, switchmid
	
switchfinal:
	ldwio r6, 0(r5) # r6 = value of switches
	andi r6, r6, 0x1 # isolate switch 0x1
	
	addi r8, r8, -1
	bne r8,r0,switchfinal
	
	beq r6, r0, done
	bne r6, r0, switchfinal

done:
	pop r8
	pop r7
	pop r6
	pop r5

	ret
*/
#-------------------------------------------------------------------
# Author: Megan Doherty
# Wait for an edge on switch SW0. The routine should wait until SW0
# goes up and down. No registers should be affected.

switch0:
.EQU SWITCHES, 0x00008850
    push r5
    push r6
    push r7
    push r8

    ori r5,r0,SWITCHES  # r5 = address of switches

sw1:
    ldwio r6,0(r5)      # r6 = switches value

    ori r7,r0,65535     # r7 = count to ten thousand
bncsw1:
    ldwio r8,0(r5)      # r8 = reread switches
    bne r8,r6,sw1       # go back to scan if different

    addi r7,r7,-1
    bne r7,r0,bncsw1    # repeat 10000 times

    andi r6,r6,1        # r6 = SW0
    beq r6,r0,sw1       # keep checking until SW0 is on

sw2:
    ldwio r6,0(r5)      # r6 = switches value

    ori r7,r0,65535     # r7 = count to ten thousand

xxsw2:
    ldwio r8,0(r5)      # r8 = reread switches
    bne r8,r6,sw2       # go back to scan if different

    addi r7,r7,-1
    bne r7,r0,xxsw2     # repeat 10000 times

    andi r6,r6,1        # r6 = SW0
    bne r6,r0,sw2       # keep checking until SW0 is off

    pop r8              # remove r8
    pop r7              # remove r7
    pop r6              # remove r6
    pop r5              # remove r5
    ret

#==================================================================		

# Subroutine: reset4

# Authors: Megan Doherty

# This subroutine is resetting the four stored digits to a certain value (e.g. all zero).

# No registers should be affected. R5 and R4 are pushed and popped off of the stack.

 

reset4:

    push r4               # Push r4 on stack

    push r5               # Push r5 on stack

 

    ori r5,r0,code     # r5 = digits

    ori r4,r0,3            # Digit 1

    stb r4,0(r5)

    ori r4,r0,2           # Digit 2

    stb r4,1(r5)

    ori r4,r0,0           # Digit 3

    stb r4,2(r5)

    ori r4,r0,1           # Digit 4

    stb r4,3(r5)

 

    pop r5                # Pop r5 off the stack

    pop r4                # Pop r4 off the stack

#==================================================================		
	
#Thales Santos and Alexis Savoie
#This subroutine sends the 16 LSB's to the hex display
#No registers affected
#No values passed

	
outhex:
	push r2
	
	ori r2, r0, 0x88A0
	sthio r3, 0(r2)
	
	pop r2
	ret

#==================================================================		
	
#Thales Santos and Alexis Savoie
#This subroutine sends the 16 LSB's to the leds
#No registers affected
#No values passed
	
outled:
	push r2
	
	ori r2, r0, 0x8880
	sthio r3, 0(r2)
	
	pop r2
	ret

#==================================================================			
	
/*----------------------------------------------------------
fireworks Subroutine:
 Authors: Raymond Laks, Drew Graham    Date: May,31, 2018
 Used to display LED pattern for 10 seconds
 Input Registers: none
 Output Registers: none
 Registers Affected: none
*/
  
fireworks: 

  push r10
  push r5
  push r6
  push r7
  push r8
  push r11
  
  # initialize registers for display
  ori r7,r0,1
  ori r8,r0,4096
  
  ori r10,r0,0x8870 
  ori r5,r0,100 # count to 10 sec
  
  # count in 100 ms
  loopa:
  ldbio r6,0(r10)
  andi r6,r6,16
  beq r6,r0,loopa
  loopb:
  ldbio r6,0(r10)
  andi r6,r6,16
  bne r6,r0,loopb
  
  addi r5,r5,-1
  bgt r7,r8,flash # flash if scrolling finished
  muli r7,r7,2 # scroll LEDs
  flash:
  xori r7,r7,0xFFFF # flash LEDs
  ori r11,r0,0x8880 
  sthio r7,0(r11)  # display on LEDs
  bne r5,r0,loopa
  
  sthio r0,0(r11) # reset LEDs
  
  pop r11
  pop r8
  pop r7
  pop r6
  pop r5
  pop r10
  
  ret

#==================================================================	
#End of subroutines, stack space and memory architecture below
code: .byte 3,2,0,1 	# the four digits in the secret code
#-------------------------------------------------------------------
.skip 200 				# stack = 200 bytes = 50 words
stacktop: 				# end of stack space allocation
#-------------------------------------------------------------------
.end