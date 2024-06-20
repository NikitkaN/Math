CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -ggdb
TST_LIBS := -lcheck -lm -lpthread
OS := $(shell uname -s)

ifeq ($(OS),Linux)
	CFLAGS+=-D LINUX
	TST_LIBS+= -lcheck_pic -lrt -lsubunit
else
	ifeq ($(OS),Darwin)
		CFLAGS+=-D MAC
	endif
endif

all: clean test gcov_report 
s21_math.o:
	$(CC) $(CFLAGS) -c s21_math.c -o s21_math.o
s21_test.o: s21_math_test.c
	$(CC) $(CFLAGS) -c s21_math_test.c -o s21_test.o
s21_math.a: s21_math.o
	@ar rcs s21_math.a s21_math.o 
	ranlib s21_math.a
s21_math_test.c: 	s21_math.check
	checkmk clean_mode=1 s21_math.check > s21_math_test.c
test: s21_math.a s21_test.o
	$(CC) $(CFLAGS) s21_test.o s21_math.a $(TST_LIBS) -o test
	@./test
clean:
	@rm -rf *.o *.a test gcov_test *.gcno *.gcda *.dSYM *.info ./report s21_math_test.c
check:
	checkmk clean_mode=1 s21_math.check > s21_math_test.c

gcov_report: gcov_test.info
	@genhtml -o report/ gcov_test.info
	@open report/index.html
	
gcov_test.info: gcov_test gcov_test.gcda
	@lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .

gcov_test: s21_math_test.c s21_math.a
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage s21_math_test.c s21_math.c s21_math.a $(TST_LIBS) -o gcov_test

gcov_test.gcda: gcov_test
	@chmod +x *
	@./gcov_test

leak:
	CK_FORK=no leaks -atExit -- ./test
	CK_FORK=no leaks -atExit -- ./gcov_test

clang-format:
	mv ../materials/linters/.clang-format .clang-format
	clang-format -i *.c *.h
	clang-format -n *.c *.h
	mv .clang-format ../materials/linters/.clang-format

cppcheck:
	cppcheck s21_math.c 

valgrind:
	CK_FORK=no valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./test
	CK_FORK=no valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./gcov_test
