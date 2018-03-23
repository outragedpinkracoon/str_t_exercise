#include <stddef.h>
#include "unity.h"
#include "str_t.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hello(void)
{
   TEST_ASSERT_EQUAL_STRING("Hello, World!", hello());
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_hello);

   UnityEnd();

   return 0;
}
