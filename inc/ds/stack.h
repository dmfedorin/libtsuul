#ifdef __cplusplus
extern "C" {
#endif

#ifndef TSUUL_STACK_H__
#define TSUUL_STACK_H__

#include <stddef.h>

struct stack {
	void *data;
	size_t size, cap, stride;
};

struct stack stack_create(size_t stride);
void stack_destroy(struct stack *st, void (*dstr_fn)(void *));
void stack_push(struct stack *st, void const *item);
void const *stack_peek(struct stack const *st, size_t ind);
void *stack_pop(struct stack *st, size_t ind);
void stack_print(struct stack const *st, void (*prt_fn)(void const *));

#endif

#ifdef __cplusplus
#endif
