#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

Point* mallocPoint(){
  Point* pPt = (Point*)malloc(sizeof(Point));
  return pPt;
}
void freePoint(Point* pPt){
  free(pPt);
}
int fprintfPoint(FILE* pFOut, Point* pPt){
  int nWritten;
  nWritten = fprintf(pFOut, "%d %f %f\n", pPt->id, pPt->x, pPt->y);
  return nWritten;
}
int fscanfPoint(FILE* pFIn, Point* pPt){
  int nRead;
  int idR;
  float xR;
  float yR;

  if(pPt == (Point*)NULL)
    return 0;
  nRead = fscanf(pFIn, "%d %f %f", &idR, &xR, &yR);
  if(nRead != 3)
    return 0;

  pPt->id = idR;
  pPt->x = xR;
  pPt->y = yR;

  return 1;
}

int fwritePoint(FILE* pFOut, Point* pPt){
  int nWritten = fwrite(pPt, sizeof(Point), 1, pFOut);
  return nWritten;
}
int freadPoint(FILE* pFIn, Point* pPt){
  int nRead;
  nRead = fread(pPt, sizeof(Point), 1, pFIn);
  if(nRead != 1)
    return 0;

  return nRead;
}
