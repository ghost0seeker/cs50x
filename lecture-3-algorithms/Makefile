CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDLIBS = -lcs50

# Find all .c files in the current directory
SRCS = $(wildcard *.c)

# Generate a list of executable names from the .c files
# For example, if SRCS is "myprogram.c anotherprogram.c",
# EXECS will become "myprogram anotherprogram"
EXECS = $(patsubst %.c,%,$(SRCS))

.PHONY: all clean

# The 'all' target now depends on all the generated executables
all: $(EXECS)

# This is a pattern rule: it applies to any target that ends in '.c'
# and tells Make how to build it from a '.c' file.
# '%': The stem (e.g., 'myprogram', 'anotherprogram')
# '$<': The first prerequisite (e.g., 'myprogram.c', 'anotherprogram.c')
# '$@': The target (e.g., 'myprogram', 'anotherprogram')
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -f $(EXECS)