CC = gcc

SRC = main.c modules/bubbleSort.c
OBJ = $(SRC:.c=.o)

TARGET = program

CFLAGS_DEBUG = -Wall -Wextra -g -std=c11

CFLAGS_OPT = -Wall -O2 -std=c11

all: debug

debug: $(OBJ)
	$(CC) $(CFLAGS_DEBUG) -o $(TARGET) $(OBJ)

opt: $(OBJ)
	$(CC) $(CFLAGS_OPT) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
