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

void test_str_new_from_raw_parts(void)
{
  char *input_string = "Sandwich";
  int input_length = 8;
  str_t output;
  str_new_from_raw_parts(&output, input_string, input_length);
  TEST_ASSERT_EQUAL_UINT(8, output.len);
  TEST_ASSERT_EQUAL_STRING("Sandwich", output.ptr);
  str_free(&output);
}

void test_str_new_from_zero_terminated(void)
{
  char *input_string = "Wrap";
  str_t output;
  str_new_from_zero_terminated(&output, input_string);
  TEST_ASSERT_EQUAL_UINT(4, output.len);
  TEST_ASSERT_EQUAL_STRING("Wrap", output.ptr);
  str_free(&output);
}

void test_str_copy(void)
{
  str_t input;
  str_new_from_zero_terminated(&input, "Banana");
  str_t output;
  str_copy(&input, &output);
  TEST_ASSERT_EQUAL_STRING("Banana", output.ptr);
  TEST_ASSERT_EQUAL_UINT(6, output.len);
  str_free(&input);
  str_free(&output);
}

void test_str_move(void)
{
  str_t input;
  str_new_from_zero_terminated(&input, "Apple");
  str_t output;
  str_move(&input, &output);
  TEST_ASSERT_EQUAL_STRING("Apple", output.ptr);
  TEST_ASSERT_EQUAL_UINT(5, output.len);
  TEST_ASSERT_NULL(input.ptr);
  TEST_ASSERT_EQUAL_UINT(0, input.len);
  str_free(&input);
  str_free(&output);
}

void test_str_concat(void)
{
  str_t left;
  str_t right;
  str_new_from_zero_terminated(&left, "Banana");
  str_new_from_zero_terminated(&right, "Apple");
  str_t output = str_concat(&left, &right);
  TEST_ASSERT_EQUAL_STRING("BananaApple", output.ptr);
  TEST_ASSERT_EQUAL_UINT(11, output.len);
  str_free(&left);
  str_free(&right);
  str_free(&output);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_hello);
   RUN_TEST(test_str_new_from_raw_parts);
   RUN_TEST(test_str_new_from_zero_terminated);
   RUN_TEST(test_str_copy);
   RUN_TEST(test_str_move);
   RUN_TEST(test_str_concat);

   UnityEnd();

   return 0;
}
