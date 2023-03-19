#ifdef __cplusplus
extern "C" {
#endif

#ifndef TSUUL_INT_CONT_CTG_H__
#define TSUUL_INT_CONT_CTG_H__

#include <stddef.h>

void init_cont_ctg(void **data, size_t *size, size_t *cap, size_t stride);

/*
 * call these functions before every *potential* grow / shrink.
 * `*data` and `*cap` will only be modified if they actually need to be.
 */
void grow_cont_ctg(void **data, size_t size, size_t *cap, size_t stride);
void shrink_cont_ctg(void **data, size_t size, size_t *cap, size_t stride);

void cont_ctg_fn(void *data, size_t stride, size_t size, void (*fn)(void *));

#endif

#ifdef __cplusplus
}
#endif
