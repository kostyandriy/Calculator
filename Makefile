CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage
TEST_LIBS = -lcheck -lm
HEADER = Calc.h
OS = $(shell uname)

ifeq ($(OS), Darwin)
	TEST_LIBS = -lcheck -lm
else
	TEST_LIBS = -lcheck -lsubunit -lpthread -lrt -lm -D_GNU_SOURCE
endif


all: Calc 

Calc: *.c *.h
	$(CC) $(CFLAGS) *.c *.h -o calculator $(TEST_LIBS)

style: 
	clang-format -n *c *h

do_style: 
	clang-format -i *c *h
	
clean: 
	rm -rf *.o *.a calculator

rebuild: clean all
