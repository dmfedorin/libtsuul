#include <stdio.h>
#include <stdlib.h>

#include "test.h"

void ds_arraylist(void);

void test_group_begin(char const *name)
{
	printf("beginning test group '%s'\n", name);
}

void test_perform(char const *name, bool assertion)
{
	printf("test '%s' - %s\n", name, assertion ? "PASSED" : "FAILED");
	if (!assertion)
		exit(-1);
}

void test_group_finish(char const *name)
{
	printf("finished test group '%s'\n", name);
}

int main(void)
{
	ds_arraylist();
	return 0;
}
