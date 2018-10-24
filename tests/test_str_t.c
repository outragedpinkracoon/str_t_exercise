#include <stddef.h>
#include <stdlib.h>

#include "unity.h"
#include "str_t.h"

#include "strings.h"

void setUp(void) { BYTES_ASSIGNED = 0; }

void tearDown(void) { BYTES_ASSIGNED = 0; }

void test_str_new_from_raw_parts(void)
{
  char* input = "hullo pal";
  str_t* result = str_new_from_raw_parts(input, 9);
  TEST_ASSERT_EQUAL_INT(result->len, 9);
  TEST_ASSERT_EQUAL_STRING(result->ptr, input);
}

void test_str_new_from_zero_terminated(void)
{
  char* input = "hullo pal";
  str_t* result = str_new_from_zero_terminated(input);
  TEST_ASSERT_EQUAL_INT(result->len, 9);
  TEST_ASSERT_EQUAL_STRING(result->ptr, input);
}

void test_str_free(void)
{
  str_t* input = str_new_from_raw_parts("hullo", 5);
  TEST_ASSERT_EQUAL(16, BYTES_ASSIGNED);

  str_free(&input);

  TEST_ASSERT_EQUAL(0, BYTES_ASSIGNED);
  TEST_ASSERT_NULL(input);
}

void test_str_copy_to_zero_terminated_success_equal_to(void) {
  str_t* input = str_new_from_raw_parts("nom", 3);
  long size_needed = 4 * sizeof(char);

  char* p = malloc(size_needed);

  str_err_t error = str_copy_to_zero_terminated(input, p, size_needed);
  TEST_ASSERT_EQUAL_STRING(p, "nom");
  TEST_ASSERT_EQUAL(error, STR_T_OK);
}

void test_str_copy_to_zero_terminated_success_more_than(void) {
  str_t* input = str_new_from_raw_parts("nom", 3);
  long size_needed = 5 * sizeof(char);

  char* p = malloc(size_needed);

  str_err_t error = str_copy_to_zero_terminated(input, p, 5);
  TEST_ASSERT_EQUAL_STRING(p, "nom");
  TEST_ASSERT_EQUAL(error, STR_T_OK);
}

void test_str_copy_to_zero_terminated_failure_less_than(void) {
  str_t* input = str_new_from_raw_parts("nom", 3);
  char* p = malloc(4 * sizeof(char));

  str_err_t error = str_copy_to_zero_terminated(input, p, 2);
  TEST_ASSERT_EQUAL(error, STR_T_BUFFER_TOO_SMALL);
}

void test_str_copy(void) {
  str_t* input1 = str_new_from_raw_parts("october", 7);
  str_t* input2 = str_new_from_raw_parts("december", 8);
  str_copy(input1, input2);

  TEST_ASSERT_EQUAL_STRING(input1->ptr, "october");
  TEST_ASSERT_EQUAL_STRING(input2->ptr, "october");
  TEST_ASSERT_EQUAL_INT(input2->len, 7);
  TEST_ASSERT_NOT_EQUAL(input2->ptr, input1->ptr);
}

int main(void)
{
   UnityBegin("tests/test_str_t.c");

   RUN_TEST(test_str_new_from_raw_parts);
   RUN_TEST(test_str_new_from_zero_terminated);
   RUN_TEST(test_str_free);
   RUN_TEST(test_str_copy_to_zero_terminated_success_equal_to);
   RUN_TEST(test_str_copy_to_zero_terminated_success_more_than);
   RUN_TEST(test_str_copy_to_zero_terminated_failure_less_than);
   RUN_TEST(test_str_copy);

   UnityEnd();

   return 0;
}
