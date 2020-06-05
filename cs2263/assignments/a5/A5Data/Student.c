#include "Point2D.h"
#include "Student.h"

#include <stdio.h>
#include <stdlib.h>


Student* createStudent(char* name, Point2D location)
{
	Student* stud = (Student*)malloc(sizeof(Student));
	stud->name = name;
	stud->location = location;
	
	return stud;
}
