#include "str_t.h"

#include <stdlib.h>
#include <string.h>

const char * const message = "Hello, World!";

const char *hello(void)
{
    return message;
}

str_t* str_new_from_raw_parts(const char* ptr, size_t len)
{
    str_t *result = malloc(sizeof(str_t));
    result->len = len;
    result->ptr = ptr;

    return result;
}

void str_free(str_t* p_str)
{
    free(p_str);
}

str_t* str_new_from_zero_terminated(const char* ptr)
{
    size_t length = strlen(ptr);
    return str_new_from_raw_parts(ptr, length);
}

void str_copy(const str_t *p_source, str_t *p_destination)
{
    const char *str = p_source->ptr;

    size_t source_length = p_source->len;

    size_t buffer_size = source_length + 1;

    char *buffer = malloc(buffer_size);

    strncpy(buffer, str, buffer_size);

    p_destination->ptr = buffer;
    p_destination->len = source_length;
}
