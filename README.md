# C-string Wrapper Exercise

An Exercism.io-like exercise to create a C library that provides a wrapper type for strings

# The task

To build a simple wrapper around native C strings.

The header in `include/str_t.h` declares signatures for the functions you need to implement.

Add test to `tests/test_str_t.c` to specify how the functions should behave.

Remember to ask yourself: what parts of the code should "own" and thus free any memory you allocate?

You MAY change the signatures in the header if you need to.

# Learning outcomes

* Understand how low level C's string handling is
* Understand roughtly how higher-level languages (implemented in C) might wrap low level C strings to add some safety
* Understand the tricky problem of memory ownership
* Understand how easy it is to forget to free memory you have allocated

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
