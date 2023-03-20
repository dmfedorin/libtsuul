#include <ds/arraylist.h>

#include "test.h"

void ds_arraylist(void)
{
	struct arraylist al = arraylist_create(sizeof(int));
	int const *get0, *get1;
	int i;
	
	test_group_begin("ds_arraylist");

	for (i = 0; i < 5; ++i)
		arraylist_push(&al, &i);
	test_perform("pushing items", al.size == 5);

	for (i = 5; i < 10; ++i)
		arraylist_insert(&al, &i, 0);
	test_perform("inserting items", al.size == 10);

	for (i = 0; i < 3; ++i)
		arraylist_remove(&al, 1, NULL);
	test_perform("removing items", al.size == 7);

	get0 = arraylist_get(&al, 3);
	get1 = arraylist_get(&al, 7);
	test_perform("getting items", get0 != NULL && get1 == NULL);

	test_group_finish("ds_arraylist");
	arraylist_destroy(&al, NULL);
}
