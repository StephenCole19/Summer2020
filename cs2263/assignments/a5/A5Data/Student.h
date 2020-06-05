#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include "Point2D.h"

typedef struct student
{
	char* name;
	Point2D location;
} Student;

Student* createStudent(char* name, Point2D location);

#endif
