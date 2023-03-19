#ifdef __cplusplus
extern "C" {
#endif

#ifndef TSUUL_QUEUE_H__
#define TSUUL_QUEUE_H__

#include <stddef.h>

struct queue {
	void *data;
	size_t size, cap, stride;
};

struct queue queue_create(size_t stride);
void queue_destroy(struct queue *q, void (*dstr_fn)(void *));
void queue_enqueue(struct queue *q, void const *item);
void *queue_dequeue(struct queue *q);
void const *queue_peek(struct queue const *q);
void queue_print(struct queue const *q, void (*prt_fn)(void const *));

#endif

#ifdef __cplusplus
}
#endif
