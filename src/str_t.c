#include "str_t.h"

#include <stdlib.h>
#include <string.h>

const char * const message = "Hello, World!";

const char *hello(void)
{
    return message;
}

void str_new_from_raw_parts(str_t *output, const char* ptr, size_t len)
{
    size_t buffer_size = len + 1;

    char *buffer = malloc(buffer_size);

    strncpy(buffer, ptr, buffer_size);

    output->ptr = buffer;
    output->len = len;
}

void str_free(str_t* p_str)
{
    free((void *) p_str->ptr);
}

void str_new_from_zero_terminated(str_t *output, const char* ptr)
{
    size_t length = strlen(ptr);
    str_new_from_raw_parts(output, ptr, length);
}

void str_copy(const str_t *p_source, str_t *p_destination)
{
    size_t buffer_size = p_source->len + 1;
    char *buffer = malloc(buffer_size);

    strncpy(buffer, p_source->ptr, buffer_size);

    p_destination->ptr = buffer;
    p_destination->len = p_source->len;
}

void str_move(str_t *p_source, str_t *p_destination)
{
    p_destination->ptr = p_source->ptr;
    p_destination->len = p_source->len;

    p_source->ptr = NULL;
    p_source->len = 0;
}

str_t str_concat(const str_t *p_left, const str_t *p_right)
{
    str_t result;

    size_t result_length = p_left->len + p_right->len;

    result.ptr = malloc(result_length + 1);

    char* iterator = (char*) result.ptr;

    for (size_t i = 0; i < p_left->len; i++) {
        *iterator = p_left->ptr[i];
        iterator++;
    }

    for (size_t j = 0; j < p_right->len; j++)
    {
        *iterator = p_right->ptr[j];
        iterator++;
    }
    *iterator = '\0';

    result.len = result_length;

    return result;
}
