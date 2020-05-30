GCC = gcc
CFLAGS = -g -Wall -Wshadow
TARGETS =  stringTest whereIsWaldo functionPointer sortInts
OBJS = Strings.o
HDRS = Strings.h
VAL = valgrind --tool=memcheck --leak-check=full
VAL += --verbose --log-file=

all: $(TARGETS)

stringTest: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

whereIsWaldo: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

functionPointer: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

sortedInts: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(TARGETS) *.o

