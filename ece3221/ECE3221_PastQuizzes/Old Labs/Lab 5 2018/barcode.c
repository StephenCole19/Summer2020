// barcode.c
//=========================================
// ECE 3221 CODE25 Reader - R.Tervo 2016
// Modified by: Thales Santos and Alexis Savoie
//=========================================
// requires barcode wand on DE2 PS2 port
//=========================================
//=========================================
// global pointers to DE2 Board I/O ports
volatile unsigned int *leds = (unsigned int *) 0x8880;
volatile unsigned int *hexdisplay = (unsigned int *) 0x88A0;
volatile unsigned int *hexcontrol = (unsigned int *) 0x88B0;
volatile unsigned int *ps2 = (unsigned int *) 0x88F0;
//=================================================
// this program reads the barcode wand and
// display the width (time) of the most
// recent two bars together as white:black
// on the hex display. The total number of
// black bars counted appears on the LEDs.
//=================================================


// Sending char to the terminal window 
void outchar(char ch){
	volatile int *write = (int *)0x8840;
	volatile int *check = (int *)0x8844;
	
	while(*check >> 16 == 0);
	
	*write = *write | ch;
}// end outchar

//Main program
//Allows barcode to be scanned
main( ){
int counter, whitetime, blacktime, i, currNum, decimal,digit; // local variable declaration
*hexcontrol = 0x01FF; // enable hex display with 8 digits
*hexdisplay = 0x0000; // initial hex display value
char bars[5];


while(1) { // loop forever
	
	counter = 0; // count black bars
	outchar('S'); // Sending S char to terminal to indicate start of the scan
	
	
	do {
		while( (*ps2 & 0x10) ){ }; // wait for ps2 LOW

		whitetime = *ps2 >> 8; // read the white bar time / 16

		while( !(*ps2 & 0x10)){ }; // wait for ps2 HIGH

		blacktime = *ps2 >> 8; // read the black bar time / 16
	
		if(blacktime > whitetime/2 && blacktime < whitetime * 3/2){
			currNum = 0;								
		} 
		
		else{
			currNum = 1;
		}

		
		if (counter >= 2){
			bars[(counter - 2) % 5] = currNum;
		}
		
		if((counter - 2)% 5 ==4){
			decimal = (bars[0]*16 + bars[1]*8 + bars[2]*4 + bars[3]*2 + bars[4]);
			
			if(decimal == 6){
				digit = 0;
			}
			
			else if(decimal == 17){
				digit = 1;
			}
			
			else if(decimal == 9){
				digit = 2;
			}
			
			else if(decimal == 24){
				digit = 3;
			}
			
			else if(decimal == 5){
				digit = 4;
			}
			
			else if(decimal == 20){
				digit = 5;
			}
			
			else if(decimal == 12){
				digit = 6;
			}
			
			else if(decimal == 3){
				digit = 7;
			}
			
			else if(decimal == 18){
				digit = 8;
			}
			
			else if(decimal == 10){
				digit = 9;
			}
			
			else{
				digit = 10;
			}
			
			outchar(digit + '0');
			
		}
		
		counter++; // count the black bars
		*hexdisplay = (whitetime << 16) | blacktime; // update white:black display
	}while(whitetime < 0x1000);
	
	outchar('E'); //Printing E when completing barcode scan
	outchar('\n'); //Printing a new line when completing barcode scan

	*leds = counter; // update black bar display LEDs	 
	} // end while forever
} // end main