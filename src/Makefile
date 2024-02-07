CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
SRC = C_source/*c
HEADER = C_source/*h
OS = $(shell uname)

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
	EXE_FILE=SmartCalc.app
else
	TEST_LIBS=-lcheck -lsubunit -pthread -lcheck_pic -lrt -lm
	EXE_FILE=SmartCalc
endif

all: Calc 

Calc: 
	$(CC) $(CFLAGS) $(SRC) $(HEADER) -o calculator $(TEST_LIBS)

clean:
	rm -rf calculator

do_style:
	clang-format -style=Google -i C_source/*c C_source/*h

check_style:
	clang-format -style=Google -n C_source/*c C_source/*h
