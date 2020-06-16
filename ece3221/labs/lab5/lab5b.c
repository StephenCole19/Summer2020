#include <stdlib.h>
#include <stdio.h>
	
//-------------------------------------------
// prototypes

void code25writer(char *data); // supplied below

// develop the following subroutines

void writexy(int x, int y, int color);

int   readxy(int x, int y);

int  intensity( int vga16 );

void waitonPB0( void );

void code25reader(void);

//-------------------------------------------

	
//-------------------------------------------
// MAIN PROGRAM

int main() {

code25writer("123");  // generate Code25 barcode 

while(1); // here: br here

} // end main

//-------------------------------------------
// SUBROUTINES





// END
//-------------------------------------------



//===========================================
// ** DO NOT MODIFY CODE BEYOND THIS LINE **
//===========================================
// Lab5 barcode display libary routines

//-------------------------------------------
// outhex7seg May 2020   RTervo
// write 32-bits in hex to the 7-segment displays

void outhex7seg( int x ){

 union hex {
	char b[4];  // as 4 bytes
	int  w;     // as 1 word
 } buf;	
	
char segments[] = { 
	0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
	0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71 
	};
	
	buf.b[3] = segments[ (x >> 28) & 0x0F ];
	buf.b[2] = segments[ (x >> 24) & 0x0F ];
	buf.b[1] = segments[ (x >> 20) & 0x0F ];
	buf.b[0] = segments[ (x >> 16) & 0x0F ];
    __builtin_stwio ((void *)0x10000030,buf.w);	

	buf.b[3] = segments[ (x >> 12) & 0x0F ];
	buf.b[2] = segments[ (x >>  8) & 0x0F ];
	buf.b[1] = segments[ (x >>  4) & 0x0F ];
	buf.b[0] = segments[ (x >>  0) & 0x0F ];
    __builtin_stwio ((void *)0x10000020,buf.w);	
	
} // end outhex7seg
//-------------------------------------------

//-------------------------------------------
// fill7seg May 2020   RTervo
// sends the provided segment pattern
// to all eight 7-seg displays
// e.g. fill7seg(0) blanks the displays
void fill7seg(char segs){
int x,four=0;
for(x=0;x<4;x++) four = (four << 8) | segs;
 __builtin_stwio ( (void *) 0x10000020,four); // fill 7seg hi	
 __builtin_stwio ( (void *) 0x10000030,four); // fill 7seg lo	
} // fill7seg	
//-------------------------------------------

//-------------------------------------------
// clrchar   May 2020   RTervo
// clear the vga character buffer
void clrchar(void) {
int x;
	for(x=0;x<5000;x++) 
		__builtin_stbio ((void *)(0x09000000 + x), 0);	
} // clrchar
//-------------------------------------------

//-------------------------------------------
// imager  May 2020   RTervo
void imager(int x, int y, int z) {
  if( (x<0) || (x>319) ) return;
  if( (y<0) || (y>239) ) return;
  int m=0,n=9,r=rand()&8191>>3;
  while(n--){m+=r&1;r>>=1;}
  if(z)m=31-m;z=m;z<<=5;z+=m;z<<=6;z+=m;
__builtin_sthio((short*)((x|16<<0x16|y<<9|0)*2),z);
} // imager
//-------------------------------------------

//-------------------------------------------
// plotbar   May 2020   RTervo
// plot a one pixel wide vertical bar in color
// (x0,y0) = top of bar location
// h = height of bar

void plotbar(int x0,int y0,int h,int color ){
int x=x0,y;
 for(y=y0;y<y0+h;y++) imager(x,y,color);	
}	
//-------------------------------------------

//-------------------------------------------
// clrscr   May 2020   RTervo
// clear the vga screen

void clrscr( void ) {
int x,y;
 for(y=0;y<240;y++) {
 for(x=0;x<320;x++) {
	 imager(x,y,1);
 } // end for y
 } // end for x
} // end clrscr
//-------------------------------------------

//-------------------------------------------
// code25writer   May 2020   RTervo
// displays a code25 barcode on the vga screen
// from a supplied numeric string (max 10 digits)

void code25writer(char *indata) {
// indata is a null terminated string of digits 0..9
// indata == null generates random barcode contents
	
// flag if barcode is vertically centered or randomly 	
#define randomy 0
	
__builtin_stwio ( (void *) 0x10000000,0); // clear red LED	
__builtin_stwio ( (void *) 0x10000010,0); // clear grn LED
	
printf("\x1B[0m"); 	// reset Terminal attributes
printf("\x1B[H" ); 	// home the cursor
printf("\x1B[2J"); 	// clear the screen
	
printf("ECE3221 Lab 5 : Code25 Barcodes \n");
	
int codes[] =      // 0 to 9 = 12 bar units each
{0xADA,0xD56,0xB56,0xDAA,0xAD6,0xD6A,0xB6A,0xAB6,0xD5A,0xB5A};
int start = 0x0DA; // 8 bar units right justified in 12
int end   = 0xD60; // 8 bar units  left justified in 12

clrscr();   	   // clear the vga display 

char *data = indata;  // point to process input string (default)
	
if( (indata == 0 ) || (indata[1] == 0) ) { 	
 // if null input data then
 // create random barcode content from 3 to 10 digits
	
 int  clen = (rand() % 13) + 3; // random content length
 char cnums[20];
 int x;  // index
	
 for(x=0;x<clen;x++) { // generate clen digits
 	int y = (rand() % 10);     // random digit 0..9
	cnums[x] = y + '0';        // save as ascii
 } // for
 cnums[x] = 0;        // null terminate
 data = cnums; 		  // point to process this random string	
} // if

char *p;
int len = 0;          // len = number of input characters
for(p=data;*p;p++) len++;
	
//-----------------------
// show the barcode contents in hex on the 7-seg display
// this provides the correct decoding in an obscured way
// if the input exceeds 9 digits display only dashes
	
if( len < 10 ) {	
 int numeric=0;
 for(p=data;*p;p++) numeric = numeric*10 + (*p - '0');
 outhex7seg(numeric); // show the barcode contents in hex 
} else { fill7seg(0x40); }	// dashes
//-----------------------
	
int h=75; // each bar height in pixels	
	
int d=1;  // unit bar width in pixels (default)
if( len < 12) d = 2;  // wider bars for shorter data
if( len < 7 ) d = 3;  // wider bars for shorter data
if( len < 5 ) d = 4;  // wider bars for shorter data
	
int k,x,y;
	
//-----------------------
// add start and end bars to the input string 	
// limit input to 20 digit characters
// while ignoring non-digit characters
	
char contents[25];
contents[0] = 'S';    // start bars
k=1;
for(p=data;*p && (k<21);p++) // ignore non-digits
	if( (*p>='0') && (*p<='9')) contents[k++] = *p;
contents[k++] = 'E';  // end  bars
contents[k] = 0;      // null terminate string
int length = k*12*d;  // total width in bar units	
//-----------------------

// (x0,y0) = top lefthand corner of new barcode
int y0 = randomy ? ( rand() % (200-h) ) + 20 : 120 - h/2;          
int x0 = 160 - length/2;

x=x0;
y=y0;
	
int bars;
int color;

	for(p=contents;*p;p++) {
		
  		 if( *p == 'S' ) bars = start; // start 
	else if( *p == 'E' ) bars = end;   // end
	else bars = codes[*p - '0'];       // digit
		
	for(k=0x0800; k>0; k>>=1) {
		
	 color = ( bars & k ) ? 0 : 1;
		 
	 int b;	// make d parallel lines for wider bars
	 for(b=0;b<d;b++) plotbar(x++,y,h,color);
	 } // for k
	} // for p

printf("A Code25 barcode image is displayed on the VGA screen\n");

} // code25writer
//-------------------------------------------
	