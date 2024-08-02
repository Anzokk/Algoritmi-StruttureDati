#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "Quicksort_Mergesort.h"

int compare_int(const void *a, const void *b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return (int_a > int_b) - (int_a < int_b);  // Restituisce -1, 0, o 1
}

static int array[10];
static size_t nitems;

void setUp(void) {
}

void tearDown(void) {
}

static void test_quick_sort_empty(void) {
    int nitems = 0;
    quick_sort(array, 0, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL(0, nitems);
}

static void test_quick_sort_one_element(void) {
    nitems = 1;
    array[1]=9;
    quick_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL(9, array[1]);
}

static void test_quick_sort_multiple_elements(void) {
    int array[10] = {3, 9, 7, 6, 0, 2, 1, 8, 4, 5};
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nitems = 10;
    quick_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, nitems);
}

static void test_quick_sort_already_sorted(void) {
    int sorted_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    memcpy(array, sorted_array, nitems * sizeof(int));
    quick_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, nitems);
}

static void test_quick_sort_reverse_order(void) {
    int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nitems = 10;
    quick_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, nitems);
}


static void test_merge_sort_empty(void) {
    int array[10];
    int nitems = 0;
    merge_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL(0, nitems);
}

static void test_merge_sort_one_element(void) {
    int array[10] = {9};
    int nitems = 1;
    merge_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL(9, array[0]);
}

static void test_merge_sort_multiple_elements(void) {
    int array[10] = {3, 9, 7, 6, 0, 2, 1, 8, 4, 5};
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nitems = 10;
    merge_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, nitems);
}

static void test_merge_sort_already_sorted(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nitems = 10;
    merge_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, nitems);
}

static void test_merge_sort_reverse_order(void) {
    int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nitems = 10;
    merge_sort(array, nitems, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, nitems);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_quick_sort_empty);
    RUN_TEST(test_quick_sort_one_element);
    RUN_TEST(test_quick_sort_multiple_elements);
    RUN_TEST(test_quick_sort_already_sorted);
    RUN_TEST(test_quick_sort_reverse_order);


    RUN_TEST(test_merge_sort_empty);
    RUN_TEST(test_merge_sort_one_element);
    RUN_TEST(test_merge_sort_multiple_elements);
    RUN_TEST(test_merge_sort_already_sorted);
    RUN_TEST(test_merge_sort_reverse_order);

    return UNITY_END();
}