#include <stdio.h>
#include <stdlib.h>
#define LINEL 200
int main(void){
  char line[LINEL+1];
  printf("enter 2 numbers: ");
  fgets(line, LINEL+1, stdin);

  // Note that strtod returns 0.0 on failure,
  //   which is fine until the value you read is 0.0
  char *p;
  double d1 = strtod(line, &p); //&p is a char** !
  double d2 = strtod(p, NULL);
  printf("your 2 numbers are %lf and %lf, strtod()\n", d1, d2);

  int iErr;
  iErr = sscanf(line, "%lf %lf", &d1, &d2);
  if(iErr != 2){
    return EXIT_FAILURE;
  }
  printf("your 2 numbers are %f and %f, using sscanf()\n", d1, d2);

  printf("enter a binary integer: ");
  fgets(line, LINEL+1, stdin);
  int num = strtol(line, NULL, 2);
  printf("your number is %d\n", num);



  return 0;
}
