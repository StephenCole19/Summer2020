#include <stdio.h>

int fac2(int n) {
	int val = 1 ;
	if (n == 0) {
		val = 1; return val;
	}
	while (n > 0) {
		val *= n; n --;
	}
	return val; 
}

int main(int argc, char* argv[]){
	int x = 3;
	int f = fac2(x);
	printf("%d\n", f); // RL1
}
