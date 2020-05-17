#########################################
# Created by Jean-Philippe Legault
#
# This is a comment, a comment always start with `#`
# Indentation is primordial in a Makefile.
# the steps for a target are always indented
#
##########################################

# compile with gcc, change this to clang if you prefer
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -Wall -Wextra

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help               (this command)\n"
	@printf "	make Stack              (to build your C program)\n"
	@printf "	make test               (to run every test case)\n"
	@printf "	make exit_test          (to run test cases against the exit instruction for your program)\n"
	@printf "	make push_test          (to run test cases against the push instruction for your program)\n"
	@printf "	make peek_test          (to run test cases against the peek instruction for your program)\n"
	@printf "	make pop_test           (to run test cases against the pop instruction for your program)\n"
	@printf "	make compound_test      (to run test cases against all the instruction for your program)\n"
	@printf " make my_test            (to run my test)\n"
# link our .o files to make an executable
Stack: Stack.o
	$(COMPILER) $(C_FLAGS) -o Stack Stack.o 

# compile the `Stack.o` file
Stack.o: Stack.c
	$(COMPILER) $(C_FLAGS) -c Stack.c

##################################################################
# Test Cases
test: exit_test push_test peek_test pop_test compound_test my_test

##############################
# exit test cases
exit_test: exit_test1

# run our executable by passing in the text file via stdin with `<` and passing stdout to a file with `>`
# then use a scrit to verify that the result are the same one as the one expected
exit_test1: Stack
	./Stack < Data/exit_test1.input > exit_test1.result
	./TestPassed.sh exit_test1.result Data/exit_test1.expected

##############################
# push test cases
push_test: push_test1 push_test2

push_test1: Stack
	./Stack < Data/push_test1.input > push_test1.result
	./TestPassed.sh push_test1.result Data/push_test1.expected 

push_test2: Stack
	./Stack < Data/push_test2.input > push_test2.result
	./TestPassed.sh push_test2.result Data/push_test2.expected

##############################
# peek test cases
peek_test: peek_test1 peek_test2

peek_test1: Stack
	./Stack < Data/peek_test1.input > peek_test1.result
	./TestPassed.sh peek_test1.result Data/peek_test1.expected

peek_test2: Stack
	./Stack < Data/peek_test2.input > peek_test2.result
	./TestPassed.sh peek_test2.result Data/peek_test2.expected

##############################
# pop test cases
pop_test: pop_test1 pop_test2 pop_test3

pop_test1: Stack
	./Stack < Data/pop_test1.input > pop_test1.result
	./TestPassed.sh pop_test1.result Data/pop_test1.expected

pop_test2: Stack
	./Stack < Data/pop_test2.input > pop_test2.result
	./TestPassed.sh pop_test2.result Data/pop_test2.expected

pop_test3: Stack
	./Stack < Data/pop_test3.input > pop_test3.result
	./TestPassed.sh pop_test3.result Data/pop_test3.expected

##############################
# compound test cases
compound_test: compound_test1 compound_test2 compound_test3

compound_test1: Stack
	./Stack < Data/compound_test1.input > compound_test1.result
	./TestPassed.sh compound_test1.result Data/compound_test1.expected

compound_test2: Stack
	./Stack < Data/compound_test2.input > compound_test2.result
	./TestPassed.sh compound_test2.result Data/compound_test2.expected

compound_test3: Stack
	./Stack < Data/compound_test3.input > compound_test3.result
	./TestPassed.sh compound_test3.result Data/compound_test3.expected

###############################
# my test cases
my_test: my_test1 my_test2

my_test1: Stack
	./Stack < Data/my_test1.input > my_test1.result
	./TestPassed.sh my_test1.result Data/my_test1.expected

my_test2: Stack
	./Stack < Data/my_test2.input > my_test2.result
	./TestPassed.sh my_test2.result Data/my_test2.expected


