#include "ds/arraylist.h"

#include <stdlib.h>

#include "int_cont_ctg.h"

struct arraylist arraylist_create(size_t stride)
{
	struct arraylist al;
	
	init_cont_ctg(&al.data, &al.size, &al.cap, stride);
	return al;
}

void arraylist_destroy(struct arraylist *al, void (*dstr_fn)(void *))
{
	cont_ctg_fn(al->data, al->stride, al->size, dstr_fn);
	free(al->data);
}

void arraylist_push(struct arraylist *al, void const *item)
{
}

void arraylist_insert(struct arraylist *al, void const *item, size_t ind)
{
}

void arraylist_remove(struct arraylist *al, size_t ind, void (*rm_fn)(void *))
{
}

void const *arraylist_get(struct arraylist const *al, size_t ind)
{
}

void *arraylist_get_mut(struct arraylist *al, size_t ind)
{
}

void arraylist_print(struct arraylist const *al, void (*prt_fn)(void const *))
{
	cont_ctg_fn(al->data, al->stride, al->size, (void (*)(void *))prt_fn);
}
