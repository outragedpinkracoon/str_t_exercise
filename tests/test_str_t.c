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
  char* input = "hi";
  str_t* result = str_new_from_raw_parts(input, 2);
  TEST_ASSERT_EQUAL_INT(result->len, 2);
  TEST_ASSERT_EQUAL_PTR(result->ptr, input);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_str_new_from_raw_parts);

   UnityEnd();

   return 0;
}
