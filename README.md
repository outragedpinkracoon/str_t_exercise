# C-string Wrapper Exercise

An Exercism.io-like exercise to create a C library that provides a wrapper type for strings

# The task

To build a simple wrapper around native C strings.

The header in `include/str_t.h` declares signatures for the functions you need to implement.

Add test to `tests/test_str_t.c` to specify how the functions should behave.

Remember to ask yourself: what parts of the code should "own" and thus free any memory you allocate?

**BEWARE** there are gotchas hidden in this starter code. It is your task to find them.

You MAY change the signatures in the header if you need to.

# Learning outcomes

Understand:

* how low-level C's string handling is
* how higher-level languages (possibly implemented in C) might wrap low level C strings to add some safety
* the tricky problem of memory ownership and when/where to free allocated memory
* how easy it is to forget to free memory you have allocated
* the difference between passing a struct as a pointer versus by value.

# Usage

Build and run the tests:

```
$ make test
```

Clean build outputs:

```
$ make clean
```

Clean build outputs and remove downloaded dependencies:

```
$ make clobber
```

To run the memory error detector. Install [valgrind](http://valgrind.org/):

```sh
# First time only (Mac)
$ brew install valgrind

# First time only (Ubuntu/Debian)
$ sudo apt-get install valgrind
```

From then on ...

```
$ make memcheck
```
