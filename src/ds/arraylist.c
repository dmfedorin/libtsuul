#include "ds/arraylist.h"

struct arraylist arraylist_create(size_t stride)
{
}

void arraylist_destroy(struct arraylist *al, void (*dstr_fn)(void *))
{
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
}
