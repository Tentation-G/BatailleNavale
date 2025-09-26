CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99
TARGET = battlechip

# Tous les fichiers sources
SOURCES = main.c board/board.c input/input.c game/game.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean