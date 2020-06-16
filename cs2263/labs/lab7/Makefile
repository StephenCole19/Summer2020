
build: sortTest sortPoints

sortTest: sortTest.c
	gcc -o sortTest -Wall sortTest.c

sortPoints: Point2D.c sortPoint2D.c
	gcc -o sortPoints -Wall Point2D.c sortPoint2D.c -std=c99 -lm
