SRC_DIR := src
INC_DIR := inc
LIB_DIR := lib

CC := gcc
AR := ar

CFLAGS := -std=c89 -pedantic -c -I$(INC_DIR)
ARFLAGS := -rc

OUT_A := libtsuul.a

SOURCES := \
	ds/arraylist.c \
	ds/string.c \
	ds/queue.c \
	ds/stack.c
