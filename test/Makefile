include config.mk

OBJECTS := $(patsubst %.c, $(LIB_DIR)/%.o, $(SOURCES))

all: $(OUT_BIN)

clean:
	rm -f $(OUT_BIN)
	rm -rf $(LIB_DIR)/*

$(OUT_BIN): $(OBJECTS) ../libtsuul.a
	$(LD) $(LDFLAGS) -o $@ $^

$(LIB_DIR)/%.o: %.c
	@ mkdir -p $@
	@ rmdir $@
	$(CC) $(CFLAGS) -o $@ $<
