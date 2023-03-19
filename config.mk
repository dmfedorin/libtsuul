SRC_DIR := src
INC_DIR := inc
LIB_DIR := lib

CC := gcc
AR := ar

CFLAGS := -std=c89 -pedantic -c -I$(INC_DIR)
ARFLAGS := -rc

OUT_A := libtsuul.a

# if you do not need a given source in your build of libtsuul, remove it.
# however, avoid removing anything prefixed `int_` unless you know what you are
# doing and understand how not to break your build.
SOURCES := \
	ds/arraylist.c \
	ds/string.c \
	ds/queue.c \
	ds/stack.c \
	ds/int_cont_ctg.c
