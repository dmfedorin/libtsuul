include config.mk

OBJECTS := $(patsubst %.c, $(LIB_DIR)/%.o, $(SOURCES))

all: $(OUT_A)

clean:
	rm -f $(OUT_A)
	rm -rf $(LIB_DIR)/*

$(OUT_A): $(OBJECTS)
	$(AR) $(ARFLAGS) -o $@ $^

$(LIB_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $@
	@ rmdir $@
	$(CC) $(CFLAGS) -o $@ $<
