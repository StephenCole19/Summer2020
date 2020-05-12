/* 
ECE3221 LAB 2 
----------------------------------------------- 
DATE: 24 May 2018   NAME:  Alexis Savoie and Thales Santos
----------------------------------------------- 
USES UNB EXPANSION BOARD to scan hex keypad
- manually control keypad rows from switches
- displays raw scancodes on the LEDs
- displays raw scancodes on the HEX display
-----------------------------------------------
CONNNECT PORT PD to keypad
-----------------------------------------------
** KEYPAD REQUIRES Vcc FOR PULLUP RESISTORS **
-----------------------------------------------
*/
 
.include "nios_macros.s"
.global _start
_start:

#Initializing necessary addresses
ori r11,r0,0x8880

ori r12,r0,0x8890

ori r13, r0, 0x8930

ori r14, r0, 0x8934

ori r15,r0,0x88A0

ori r16,r0,0x88B0 
 
#Initializing hex display and led on expansion board
ori r5, r0, 0x1FF

sthio r5,0(r16)

ori r4, r0, 0x000F
 
stbio r4,0(r14)
 
ori r3,r0,0x0800
sthio r3,0(r12)

stbio r0,0(r15)

ori r8,r0,0xFF 
 
#Navigating through rows and getting lookup table values
ori r17,r17,0xEEEE 
 
slli r17,r17,0x10

ori r17, r17, 0xEEEE

ori r7,r0, MYTAB
 
top: 
	#Shifting values
	roli r17,r17,0x01
	
	andi r1,r17,0x0F
	
	stbio r1,0(r13)
	
	ori r1,r1,0xF0      
 
 	#Allowing value to stabalize
	nop
	 
	nop
	
	nop
	
	nop
 
 	#Retrieving inputted value and decoding if necessary
	ldbio r2,0(r13)
	
	andi r2,r2,0x00FF
	
	beq r2,r1,top
 
	br decode
 
display:
	#Displaying actual hex value using the look up table 
	slli r21,r21,4
	
	andi r19,r19,0xF
	
	or r21,r21,r19
	
	stwio r21,0(r15)
	
	sthio r2,0(r11)
	
	ldbio r6,0(r13)
	
	andi r6,r6, 0xFF
	
	bne r6,r2,top
	
clear:
	or r9,r0,r0
	
idle:
	nop

	nop

	nop

	nop

	addi r9,r9,0x01

	bne r9,r8,idle

	ldbio r6,0(r13)
	
	andi r6,r6, 0xFF

	beq r6,r2,clear

	br top
 
decode:
	#Navigate to lookup table
	ori r18,r0,MYTAB

	addi r20,r18,0x20
 
index:
	#Searching lookup table
	ldb r3,0(r18)
	
	ldb r19,1(r18)
	
	andi r3,r3,0xFF
	
	andi r19,r19,0xFF
	
	beq r2,r3,display
 
	addi r18,r18,0x02
	
	bne r18,r20,index
	
	ori r19,r0, 0xFF
	
	br display
# -----------------------------------------------
# lookup table for sixteen scan codes
# and the corresponding hex key label
# Each line contains: scancode, keycode
.org 1000
MYTAB:
.byte 0xEE,1
.byte 0xDE,2
.byte 0xBE,3
.byte 0x7E,0xA
.byte 0xED,4
.byte 0xDD,5
.byte 0xBD,6
.byte 0x7D,0xB
.byte 0xEB,7
.byte 0xDB,8
.byte 0xBB,9
.byte 0x7B,0xC
.byte 0xE7,0xE
.byte 0xD7,0
.byte 0xB7,0xF
.byte 0x77,0xD
.end
