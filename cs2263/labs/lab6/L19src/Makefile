CC = gcc
CFLAGS = -pg -std=c99
HEADERS = Point.h
OBJS =    Point.o
TARGETS = genPointsTxt genPointsBin genPointsBlob pointsTxt2Bin pointsBin2Txt pointsSeekBin
INSTALL_DIR = ./bin

install: all
	mkdir -p $(INSTALL_DIR)
	mv -f $(TARGETS) $(INSTALL_DIR)
genPointsTxt: genPointsTxt.o $(OBJS)
	$(CC) -o $@ genPointsTxt.o $(CFLAGS) $(OBJS)

genPointsBin: genPointsBin.o $(OBJS)
	$(CC) -o $@ genPointsBin.o $(CFLAGS) $(OBJS)

genPointsBlob: genPointsBlob.o $(OBJS)
	$(CC) -o $@ genPointsBlob.o $(CFLAGS) $(OBJS)

pointsTxt2Bin: pointsTxt2Bin.o $(OBJS)
	$(CC) -o $@ pointsTxt2Bin.o $(CFLAGS) $(OBJS)

pointsBin2Txt: pointsBin2Txt.o $(OBJS)
	$(CC) -o $@ pointsBin2Txt.o $(CFLAGS) $(OBJS)

pointsSeekBin: pointsSeekBin.o $(OBJS)
	$(CC) -o $@ pointsSeekBin.o $(CFLAGS) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) -c $*.c $(CFLAGS)

clean: *.o
	rm -f *.o $(TARGETS) $(INSTALL_DIR)/*

all: $(TARGETS)
