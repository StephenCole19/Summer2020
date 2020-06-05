busAssignment: readRoutes.c PointList.c Point2D.c BusRoute.c Student.c
	gcc -o busAssignment -Wall readRoutes.c PointList.c Point2D.c BusRoute.c Student.c

test: sample_test

sample_test: busAssignment
	cat students.txt | ./busAssignment busroutes.txt > test.results
	./TestPassed.sh ./test.results ./test.expected

clean:
	rm *.o
