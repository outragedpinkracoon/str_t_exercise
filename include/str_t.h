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

// ------------------------------------------------------------------------------------------------
// Creating

/*
 * Given a pointer and a length allocate a new str_t.
 */
str_t* str_new_from_raw_parts(const char* ptr, size_t len);

/*
 * Given just a pointer to a zero-terminated char array allocate a new str_t.
 */
str_t* str_new_from_zero_terminated(const char* ptr);

// ------------------------------------------------------------------------------------------------
// Safely destroying

/*
 * Destroy a str_t.
 *
 * Frees any memory allocated. After calling this the pointer must not be used.
 */
void str_free(str_t* p_str);

// ------------------------------------------------------------------------------------------------
// Moving out

/*
 * Copy the inner string held in p_source to p_destination.
 *
 * STR_T_BUFFER_TOO_SMALL is returned if dest_size is not big enough to hold the entire inner
 * string including the nul-terminator.
 */
str_err_t str_copy_to_zero_terminated(const str_t* p_source, char* p_destination, size_t dest_size);

// ------------------------------------------------------------------------------------------------
// Assignment

/*
 * Create a duplicate of the string held in p_source.
 *
 * Afterwards, p_source and p_destination are completely independent and share no resources.
 */
void str_copy(const str_t* p_source, str_t* p_destination);

/*
 * Move the resources of p_source into p_destination.
 *
 * Afterwards, p_source will be empty cannot be used.
 */
void str_move(const str_t* p_source, str_t* p_destination);

// ------------------------------------------------------------------------------------------------
// Operators

/*
 * Return a new str_t that it is the concatination of p_str and p_other.
 */
str_t* str_concat(const str_t* p_str, str_t* p_other);

/*
 * Mutate p_str so that it is the concatination of p_str and p_other.
 */
void str_extend(const str_t* p_str, str_t* p_other);

// ------------------------------------------------------------------------------------------------
// TODO remove this - was used to prove compilation works
const char *hello(void);

#endif
