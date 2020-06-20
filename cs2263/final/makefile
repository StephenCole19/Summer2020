routeEditor: readRoutes.c PointList.c Point2D.c BusRoute.c LinkedList.c
	gcc -lm -std=c99 -o routeEditor -Wall readRoutes.c PointList.c Point2D.c BusRoute.c LinkedList.c

test: test_list test_add_route test_remove_route test_add_stop test_remove_stop test_save

test_list: routeEditor
	./routeEditor busroutes.txt < test_list.in > ./test_list.results
	./TestPassed.sh ./test_list.results ./test_list.expected

test_add_route: routeEditor
	./routeEditor busroutes.txt < test_add_route.in > ./test_add_route.results
	./TestPassed.sh ./test_add_route.results ./test_add_route.expected

test_remove_route: routeEditor
	./routeEditor busroutes.txt < test_remove_route.in > ./test_remove_route.results
	./TestPassed.sh ./test_remove_route.results ./test_remove_route.expected

test_add_stop: routeEditor
	./routeEditor busroutes.txt < test_add_stop.in > ./test_add_stop.results
	./TestPassed.sh ./test_add_stop.results ./test_add_stop.expected	

test_remove_stop: routeEditor
	./routeEditor busroutes.txt < test_remove_stop.in > ./test_remove_stop.results
	./TestPassed.sh ./test_remove_stop.results ./test_remove_stop.expected

test_save: routeEditor
	./routeEditor routes.txt < test_save.in > ./test_save.results
	./TestPassed.sh ./routes.txt ./routes1.txt

clean:
	rm *.o *.results
