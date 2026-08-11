CC       := gcc
TARGET   := game_of_life

# Alle C-Dateien im Projektordner automatisch erfassen
SOURCES  := $(wildcard *.c)
OBJECTS  := $(SOURCES:.c=.o)
DEPS     := $(OBJECTS:.o=.d)

CPPFLAGS :=
CFLAGS   := -std=c11 -Wall -Wextra -Wpedantic -Wshadow -Wconversion \
            -Wstrict-prototypes -Wmissing-prototypes -MMD -MP
LDFLAGS  :=
LDLIBS   :=

.PHONY: all run debug release clean rebuild

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -O0 -g3 -fsanitize=address,undefined
debug: LDFLAGS += -fsanitize=address,undefined
debug: clean $(TARGET)

release: CFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPS)

rebuild: clean all

-include $(DEPS)
