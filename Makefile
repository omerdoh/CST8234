CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall -w -Wno-declaration-after-statement -leak-check=full
OUT_EXE = "assignment1"
FILES = LinkedListFunctions.c doublyLinkedListFunctions.c

PART_B: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

PartB.o : LinkedListFunctions.h doublyLinkedListFunctions.h
