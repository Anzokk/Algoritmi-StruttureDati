#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "unity.h"
#include "EditDistance.h"

static const char* s1;
static const char* s2;
static int size_s1;
static int size_s2;

void setUp(void){
    s1="tassa";
    s2="passato";
    size_s1 = strlen(s1);
    size_s2 = strlen(s2);
}

void tearDown (void){

}

void test_s1_no_char_ED (void){
    s1="";
    TEST_ASSERT_EQUAL_INT (size_s2, edit_distance(s1,s2));
}

void test_s2_no_char_ED (void){
    s2="";
    TEST_ASSERT_EQUAL_INT (size_s1, edit_distance(s1,s2));
}

void test_s1_s2_no_char_ED (void){
    s1="";
    s2="";
    TEST_ASSERT_EQUAL_INT (0, edit_distance(s1,s2));
}

void test_s2_equal_s1_ED (void){
    s2 = s1;
    TEST_ASSERT_EQUAL_INT (0, edit_distance(s1,s2));
}

void test_s1_equal_s2_ED (void){
    s1 = s2;
    TEST_ASSERT_EQUAL_INT (0, edit_distance(s1,s2));
}

void test_s1_no_char_ED_Dyn (void){
    s1="";
    TEST_ASSERT_EQUAL_INT (size_s2, edit_distance_dyn(s1,s2));
}

void test_s2_no_char_ED_Dyn (void){
    s2="";
    TEST_ASSERT_EQUAL_INT (size_s1, edit_distance_dyn(s1,s2));
}

void test_s1_s2_no_char_ED_Dyn (void){
    s1="";
    s2="";
    TEST_ASSERT_EQUAL_INT (0, edit_distance_dyn(s1,s2));
}

void test_s2_equal_s1_ED_Dyn (void){
    s2 = s1;
    TEST_ASSERT_EQUAL_INT (0, edit_distance_dyn(s1,s2));
}

void test_s1_equal_s2_ED_Dyn (void){
    s1 = s2;
    TEST_ASSERT_EQUAL_INT (0, edit_distance_dyn(s1,s2));
}

void test_s1_s2_ED_equal_s1_s2_Ed_Dyn (void){
    TEST_ASSERT_EQUAL_INT (edit_distance(s1,s2), edit_distance_dyn(s1,s2));
}

int main (void){
    UNITY_BEGIN();
    RUN_TEST (test_s1_no_char_ED);
    RUN_TEST (test_s2_no_char_ED);
    RUN_TEST (test_s1_s2_no_char_ED);
    RUN_TEST (test_s2_equal_s1_ED);
    RUN_TEST (test_s1_equal_s2_ED);
    RUN_TEST (test_s1_no_char_ED_Dyn);
    RUN_TEST (test_s2_no_char_ED_Dyn);
    RUN_TEST (test_s1_s2_no_char_ED_Dyn);
    RUN_TEST (test_s2_equal_s1_ED_Dyn);
    RUN_TEST (test_s1_equal_s2_ED_Dyn);
    RUN_TEST (test_s1_s2_ED_equal_s1_s2_Ed_Dyn);
    return UNITY_END();
}