#include "int_cont_ctg.h"

#include <stdlib.h>
#include <string.h>

#define STARTING_CAP 1

void init_cont_ctg(void **data, size_t *size, size_t *cap, size_t stride)
{
	*data = malloc(stride * STARTING_CAP);
	*size = 0;
	*cap = STARTING_CAP;
}

void grow_cont_ctg(void **data, size_t size, size_t *cap, size_t stride)
{
	if (size >= *cap) {
		*cap *= 2;
		*data = realloc(*data, *cap * stride);
	}
}

void shrink_cont_ctg(void **data, size_t size, size_t *cap, size_t stride)
{
	/*
	 * for performance purposes, some projects may not want to shrink
	 * containers, even when they are unnecessarily large in memory.
	 */
#ifndef TSUUL_CONT_CTG_NO_SHRINK
	if (size <= *cap / 2) {
		void *new_data;
		
		*cap /= 2;
		new_data = malloc(*cap * stride);
		memcpy(new_data, *data, size * stride);
		free(*data);
		*data = new_data;
	}
#endif
}

void cont_ctg_fn(void *data, size_t stride, size_t size, void (*fn)(void *))
{
	size_t i;

	if (fn == NULL)
		return;

	for (i = 0; i < size; ++i)
		fn((char *)data + stride * i);
}

void mv_cont_ctg_range(void *data, size_t stride, size_t lb, size_t ub,
                       size_t dst_ind)
{
	memmove((char *)data + stride * dst_ind, (char *)data + stride * lb,
	        stride * (ub - lb));
}
