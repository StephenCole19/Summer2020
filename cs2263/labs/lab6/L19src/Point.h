typedef struct pt{
  int id;
  float x;
  float y;
}Point;

Point* mallocPoint();
void freePoint(Point* pPt);
int fprintfPoint(FILE* pOut, Point* pPt);
int fscanfPoint(FILE* pFIn, Point* pPt);
int fwritePoint(FILE* pFOut, Point* pPt);
int freadPoint(FILE* pFIn, Point* pPt);
