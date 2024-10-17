# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRCDIR = src
BUILDDIR = build
BINDIR = bin

# Find all .c files in src and its subdirectories
SRCFILES := $(shell find $(SRCDIR) -name '*.c')

# Convert .c files in src to corresponding .o files in build
OBJFILES := $(SRCFILES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Target executable file
TARGET = $(BINDIR)/stoopid

# Default rule
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files to .o files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

# Phony targets
.PHONY: all clean
