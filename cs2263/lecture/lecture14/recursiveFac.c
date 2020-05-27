#include <stdio.h>

int fac(int n) {
	int val;
	if (n == 0) {
		val = 1; return val;
	}
	val = n * fac(n-1); return val; // RL2
}

int main(int argc, char* argv[]){
	int x = 3;
	int f = fac(x);
	printf("%d\n", f); // RL1
}
