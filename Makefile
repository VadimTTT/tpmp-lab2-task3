CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src/include
TARGET = program
SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/client/*.c) $(wildcard $(SRCDIR)/server/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)/client $(OBJDIR)/server

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all run clean
