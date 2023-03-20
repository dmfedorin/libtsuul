#ifdef __cplusplus
extern "C" {
#endif

#ifndef TSUUL_INT_CONT_CTG_H__
#define TSUUL_INT_CONT_CTG_H__

#include <stddef.h>

void init_cont_ctg(void **data, size_t *size, size_t *cap, size_t stride);

/*
 * call `grow_cont_ctg()` before every *potential* grow; and, similarly, call
 * `shrink_cont_ctg()` after every *potential* shrink.
 * `*data` and `*cap` will only be modified if they actually need to be.
 */
void grow_cont_ctg(void **data, size_t size, size_t *cap, size_t stride);
void shrink_cont_ctg(void **data, size_t size, size_t *cap, size_t stride);

void cont_ctg_fn(void *data, size_t stride, size_t size, void (*fn)(void *));
void mv_cont_ctg_range(void *data, size_t stride, size_t lb, size_t ub,
                       size_t dst_ind);

#endif

#ifdef __cplusplus
}
#endif
