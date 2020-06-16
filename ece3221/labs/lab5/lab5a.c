//-------------------------------------------
// lab5a.c  ECE3221 Lab 5  June 2020   RTervo
// My first C-language program on the DE2-115
// Create a counter and write to the red LEDs
//-------------------------------------------

// use #define to name a common constant
// RLEDS = address pointing to the red LEDs

#define RLEDS (int *) 0x10000000

int main ( ) {

int count = 0;

  while( 1 ) {  // 1 is always true, defines an infinite loop
	
      // write count to the red LEDs

  	__builtin_stwio ( RLEDS, count ); 

  	count = count + 1;	

  } // end while		
	
} // end main

