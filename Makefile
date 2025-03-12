# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Target executable
TARGET := main

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): main.c
	$(CC) $(CFLAGS) $< -o $@

# Clean built files
clean:
	rm -f $(TARGET)

.PHONY: all clean
