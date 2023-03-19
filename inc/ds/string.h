#ifdef __cplusplus
extern "C" {
#endif

#ifndef TSUUL_STRING_H__
#define TSUUL_STRING_H__

#include <stddef.h>

struct string {
	char *data;
	size_t size, cap;
};

struct string string_create(void);
void string_destroy(struct string *s);
void string_push_ch(struct string *s, char ch);
void string_push_c_str(struct string *s, char const *cs);
void string_insert_c_str(struct string *s, char const *cs, size_t ind);
void string_remove(struct string *s, size_t ind);
char string_get(struct string const *s, size_t ind);
char *string_get_mut(struct string *s, size_t ind);
void string_print(struct string const *s);

#endif

#ifdef __cplusplus
}
#endif
