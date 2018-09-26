#include "str_t.h"
#include "stdlib.h"
#include "stdio.h"
#include "strings.h"

size_t BYTES_ASSIGNED = 0;

str_t* str_new_from_raw_parts(const char* ptr, size_t len) {
  size_t size = sizeof(str_t);
  str_t* p = malloc(size);

  BYTES_ASSIGNED += size;

  p->len = len;
  p->ptr = ptr;

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
