CC = gcc
all:  bin/EditDistance_test bin/EditDistance_main

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/EditDistance_test: build/EditDistance_test.o build/EditDistance.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/EditDistance_test build/EditDistance_test.o build/EditDistance.o build/unity.o

bin/EditDistance_main: build/EditDistance_main.o build/EditDistance.o $(COMMON_DEPS)
	$(CC) -o bin/EditDistance_main build/EditDistance_main.o build/EditDistance.o 

clean:
	rm -f build/* bin/*
