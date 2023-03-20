#ifndef TEST_H__
#define TEST_H__

#include <stdbool.h>

void test_group_begin(char const *name);
void test_perform(char const *name, bool assertion);
void test_group_finish(char const *name);

#endif
