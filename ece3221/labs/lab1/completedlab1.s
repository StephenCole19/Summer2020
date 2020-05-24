.global _start
_start:
br  Start  

/***
ECE3221 LAB#1 - MY FIRST NIOS-II PROGRAM                        
----------------------------------------------- 
DATE:22/05/2020 	NAME: Stephen Cole
----------------------------------------------- 
***/
.org 0x100
Start:

	movia r11,0x10000000  # r11 = address of red leds
    movia r10,0x10000040  # r10 = address of switches 
	movia r12,0x10000010  # r12 = address of green leds
	movia r3,0x1

top:
	#ldwio r3,(r10)        # load r3 from the switches
	andi r6,r3,0x8		  # force all but Bit3 to low
	srli r6,r6,0x3		  # move bit to LSB
	andi r7,r3,0x1		  # force all but Bit1 to low
	
	xor r6,r6,r7          # xor both lsb's
	
	stwio r6,(r12)		  # send r3 to green leds
	slli r3,r3,0x1		  # create new Bit0
	or r3,r3,r6
	stwio r3,(r11)        # send r3 to the red leds	

	br top                # repeat forever

#----------------------------------------------



