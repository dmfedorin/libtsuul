LIB_DIR := lib

CC := gcc
LD := gcc

CFLAGS := -std=c89 -pedantic -c -I. -I../inc
LDFLAGS := -L.. -ltsuul

OUT_BIN := test

SOURCES := \
	test.c \
	ds/arraylist.c
