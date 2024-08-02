CC = gcc
all: bin/Quicksort_MergesortTest bin/Quicksort_MergesortMain

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/Quicksort_MergesortTest: build/Quicksort_MergesortTest.o build/Quicksort_Mergesort.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/Quicksort_MergesortTest  build/Quicksort_MergesortTest.o build/Quicksort_Mergesort.o build/unity.o

bin/Quicksort_MergesortMain: build/Quicksort_MergesortMain.o build/Quicksort_Mergesort.o $(COMMON_DEPS)
	$(CC) -o bin/Quicksort_MergesortMain build/Quicksort_MergesortMain.o build/Quicksort_Mergesort.o 

clean:
	rm -f build/* bin/*
