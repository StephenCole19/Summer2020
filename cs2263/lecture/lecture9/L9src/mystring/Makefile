GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = mystring.o main.o
HDRS = mystring.h
VAL = valgrind --tool=memcheck --leak-check=full
VAL += --verbose --log-file=


%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c

mystring: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f mystring $(OBJS) 

