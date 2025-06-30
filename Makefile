# Makefile for Bank Customer Management System

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Executable name
TARGET = bank_system.exe

# Source files
SRCS = main.c functions.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile .c to .o
%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -f *.o *.exe
