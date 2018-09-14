#include <stddef.h>
#include <stdlib.h>

#include "unity.h"
#include "str_t.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_str_new_from_raw_parts(void)
{
  char* input = "hullo pal";
  str_t* result = str_new_from_raw_parts(input, 9);
  TEST_ASSERT_EQUAL_INT(result->len, 9);
  TEST_ASSERT_EQUAL_PTR(result->ptr, input);
}

void test_str_new_from_zero_terminated(void)
{
  char* input = "hullo pal";
  str_t* result = str_new_from_zero_terminated(input);
  TEST_ASSERT_EQUAL_INT(result->len, 9);
  TEST_ASSERT_EQUAL_PTR(result->ptr, input);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_str_new_from_raw_parts);
   RUN_TEST(test_str_new_from_zero_terminated);

   UnityEnd();

   return 0;
}
