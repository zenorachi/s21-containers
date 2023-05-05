CC = gcc
CFLAGS := -lstdc++ -std=c++17 -Wall -Werror -Wextra

CUR_SOURCE = ./tree/tree.cc
EXECUTABLE = test

SRC_LIST_TEST = list/list_test.cc
OBJ_LIST_TEST = list_test.o

SRC_STACK_TEST = stack/stack_test.cc
OBJ_STACK_TEST = stack_test.o

SOURCE = $(SRC_LIST_TEST) $(SRC_STACK_TEST)

UNAME = $(shell uname)

OPEN_REPORT :=
LEAKS :=

ifeq ($(UNAME), Linux)
OPEN_REPORT += xdg-open
LEAKS += valgrind --leak-check=full -s -q --track-origins=yes
endif

ifeq ($(UNAME), Darwin)
OPEN_REPORT += open
LEAKS += leaks -atExit --
endif

all: build run

clean:
	@rm -rf $(EXECUTABLE)
	@rm -rf a.out
	@rm -rf $(OBJ_LIST_TEST)
	@rm -rf $(OBJ_STACK_TEST)
	@rm -rf *.gcno *.gcda report
	@rm -rf tests.info

test:
	@$(CC) $(CFLAGS) $(SOURCE) -lgtest_main -lgtest -o $(EXECUTABLE) && ./$(EXECUTABLE)

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) -lgtest_main -lgtest -o $(EXECUTABLE) --coverage
	@./$(EXECUTABLE)
	mkdir report
	gcovr -r . --html --html-details -o ./report/coverage_report.html
	rm -f *.gcda *.gcno
	$(OPEN_REPORT) ./report/coverage_report.html

build:
	$(CC) $(CFLAGS) $(CUR_SOURCE) -o $(EXECUTABLE)

leaks_check: test
	@$(LEAKS) ./$(EXECUTABLE)

fsanitize_check: obj
	$(CC) -fsanitize=address $(CFLAGS) $(SOURCE) -lgtest_main -lgtest -o $(EXECUTABLE) && ./$(EXECUTABLE)

run:
	./$(EXECUTABLE)

.PHONY: all clean test gcov_report obj build fsanitize_check run
