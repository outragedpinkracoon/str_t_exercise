#include "str_t.h"
#include "stdlib.h"

str_t* str_new_from_raw_parts(const char* ptr, size_t len){
  str_t* p = malloc(sizeof(str_t));
  p->len = len;
  p->ptr = ptr;

  return p;
}
