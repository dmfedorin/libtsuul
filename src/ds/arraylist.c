#include "ds/arraylist.h"

#include <stdlib.h>
#include <string.h>

#include "int_cont_ctg.h"

struct arraylist arraylist_create(size_t stride)
{
	struct arraylist al;
	
	init_cont_ctg(&al.data, &al.size, &al.cap, stride);
	al.stride = stride;
	return al;
}

void arraylist_destroy(struct arraylist *al, void (*dstr_fn)(void *))
{
	cont_ctg_fn(al->data, al->stride, al->size, dstr_fn);
	free(al->data);
}

void arraylist_push(struct arraylist *al, void const *item)
{
	grow_cont_ctg(&al->data, al->size, &al->cap, al->stride);
	memcpy((char *)al->data + al->stride * al->size, item, al->stride);
	++al->size;
}

void arraylist_insert(struct arraylist *al, void const *item, size_t ind)
{
	grow_cont_ctg(&al->data, al->size, &al->cap, al->stride);
	mv_cont_ctg_range(al->data, al->stride, ind, al->size, ind + 1);
	memcpy(arraylist_get_mut(al, ind), item, al->stride);
	++al->size;
}

void arraylist_remove(struct arraylist *al, size_t ind, void (*rm_fn)(void *))
{
	if (rm_fn != NULL)
		rm_fn(arraylist_get_mut(al, ind));
	
	mv_cont_ctg_range(al->data, al->stride, ind + 1, al->size, ind);
	--al->size;
	shrink_cont_ctg(&al->data, al->size, &al->cap, al->stride);
}

void const *arraylist_get(struct arraylist const *al, size_t ind)
{
	return ind >= al->size ? NULL : (char *)al->data + al->stride * ind;
}

void *arraylist_get_mut(struct arraylist *al, size_t ind)
{
	return (void *)arraylist_get(al, ind);
}

void arraylist_print(struct arraylist const *al, void (*prt_fn)(void const *))
{
	cont_ctg_fn(al->data, al->stride, al->size, (void (*)(void *))prt_fn);
}
