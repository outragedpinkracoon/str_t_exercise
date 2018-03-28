#ifndef STR_T_H
#define STR_T_H

#include <stddef.h>

// Structure that will hold our string
typedef struct str {
  const char* ptr;
  size_t len;
} str_t;

// A type for errors
typedef enum {
  STR_T_OK               = 0,
  STR_T_BUFFER_TOO_SMALL = -1
} str_err_t;

// Creating
str_t* str_new_from_raw_parts(const char* ptr, size_t len);
str_t* str_new_from_zero_terminated(const char* ptr);

// Safely destroying
void str_free(str_t* p_str);

// Moving out
str_err_t str_copy_to_zero_terminated(const str_t* p_source, char* p_destination, size_t dest_size);

// Assignment
void str_copy(const str_t* p_source, str_t* p_destination);
void str_move(const str_t* p_source, str_t* p_destination);

// Operators
str_t* str_concat(const str_t* p_str, str_t* p_other);

// TODO remove this - was used to prove compilation works
const char *hello(void);

#endif
