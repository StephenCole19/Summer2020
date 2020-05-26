COMPILER = gcc
C_FLAGS = -Wall -Wextra


stest: Strings.o stringTest.o
	$(COMPILER) $(C_FLAGS) -o stest stringTest.o Strings.o

Strings.o: Strings.c
	$(COMPILER) $(C_FLAGS) -c Strings.c

stringTest.o: stringTest.c
	$(COMPILER) $(C_FLAGS) -c stringTest.c 
