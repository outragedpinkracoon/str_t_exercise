#include "str_t.h"
#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include "strings.h"

size_t BYTES_ASSIGNED = 0;

str_t* str_new_from_raw_parts(const char* ptr, size_t len) {
  size_t size = sizeof(str_t);
  //allocate 16 bytes for the str_t struct
  str_t* p = malloc(size);

  BYTES_ASSIGNED += size;

  //make a space in memory equal to the size of the string we want to store
  //e.g 'october' will be 7 bytes
  char* copy = malloc(len);
  //copy all the contents of the input string to the new destination in memory
  //e.g 'october' will copy 7 bytes inclusive from 'c' into copy
  memcpy(copy, ptr, len);

  //store the newly copied data in the struct
  p->len = len;
  p->ptr = copy;

  return p;
}

str_t* str_new_from_zero_terminated(const char* ptr) {
  return str_new_from_raw_parts(ptr, strlen(ptr));
}

void str_free(str_t* *p_str) {
  BYTES_ASSIGNED -= sizeof(**p_str);

  free(*p_str);
  *p_str = NULL;
}

str_err_t str_copy_to_zero_terminated(const str_t* p_source, char* p_destination, size_t dest_size) {
  if(dest_size < p_source->len) return STR_T_BUFFER_TOO_SMALL;

  memcpy(p_destination, p_source->ptr, p_source->len);

  return STR_T_OK;
}

void str_copy(const str_t* p_source, str_t* p_destination) {
  //get the size of the source string
  //e.g 'october' will be 7
  size_t size = p_source->len;

  //make some new memory based on the source string size
  //e.g 'october' will reserve 7 bytes
  char* copy = malloc(size);
  //copy the source string into the new memory, based on the source string size
  //e.g. 'october' will copy 7 bytes inclusive of 'o' into memory
  memcpy(copy, p_source->ptr, size);

  //store the newly copied data in the struct
  p_destination->ptr = copy;
  p_destination->len = p_source->len;
}

bool str_compare(const str_t* left, const str_t* right) {
  if(left->len != right->len) return false;

  size_t offset = 0;
  for(size_t i = 0; i < left->len;i++) {

    char left_current = *(left->ptr + offset);
    char right_current = *(right->ptr + offset);
    if(left_current == right_current) {
      continue;
    }
    else
    {
      return false;
    }
    offset++;
  }
  return true;
}


