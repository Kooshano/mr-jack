CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic -Iinclude
LDFLAGS ?=

ifeq ($(OS),Windows_NT)
TARGET := bin/mr-jack.exe
else
TARGET := bin/mr-jack
endif

SRC := src/mr-jack.c

.PHONY: all build run clean reset-state

all: build

build: $(TARGET)

$(TARGET): $(SRC) include/characters.h include/specials.h include/map.h include/move.h | bin state
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: build
	./$(TARGET)

clean:
	rm -f bin/mr-jack bin/mr-jack.exe

reset-state:
	rm -f state/save.bin state/replay.txt
	touch state/.gitkeep

bin:
	mkdir -p bin

state:
	mkdir -p state
