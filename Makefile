CFLAGS  = -std=c11
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -I ./include -I ./tests/vendor/src

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

clobber: clean
	rm -rf tests/vendor

tests.out: tests/test_str_t.c src/str_t.c include/str_t.h tests/vendor/src/unity.c
	@echo Compiling $@
	@cc $(CFLAGS) src/str_t.c tests/vendor/src/unity.c tests/test_str_t.c -o tests.out

tests/vendor/src/unity.c:
	cd tests; \
	test -d vendor || \
		git clone --depth 1 --branch v2.4.3 git@github.com:ThrowTheSwitch/Unity.git vendor 2> /dev/null
