CC = gcc
CFLAGS = -pg -std=c99
TARGETS = genIntBin sortInMemoryIntBin sortOnDiskBin reportIntBin
INSTALL_DIR = ./bin

install: $(TARGETS)

genIntBin: genIntBin.o
	$(CC) -o $@ genIntBin.o $(CFLAGS)

sortInMemoryIntBin: sortInMemoryIntBin.o
	$(CC) -o $@ sortInMemoryIntBin.o $(CFLAGS)

sortOnDiskBin: sortOnDiskBin.o
	$(CC) -o $@ sortOnDiskBin.o $(CFLAGS)

reportIntBin: reportIntBin.o
	$(CC) -o $@ reportIntBin.o $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c $*.c $(CFLAGS)

clean: *.o
	rm -f *.o $(TARGETS) $(INSTALL_DIR)/*

all: $(TARGETS)
