
stringListSortTest: Strings.o stringListSortTest.o
	gcc -std=c99 -o stringListSortTest -g Strings.o stringListSortTest.o

stringListTest: Strings.o stringListTest.o
	gcc -std=c99 -o stringListTest -g Strings.o stringListTest.o

stringTest1: Strings.o stringTest1.o
	gcc -std=c99 -o stringTest1 -g Strings.o stringTest1.o

stringListSortTest.o: Strings.c stringListSortTest.c
	gcc -std=c99 -c -g Strings.c stringListSortTest.c

stringListTest.o: Strings.c stringListTest.c
	gcc -std=c99 -c -g Strings.c stringListTest.c

stringTest1.o: Strings.c stringTest1.c
	gcc -std=c99 -c -g Strings.c stringTest1.c

Strings.o: Strings.c
	gcc -std=c99 -c Strings.c


clean:
	rm Strings.o
