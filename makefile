SOURCE = sha256.c
TARGET = sha256
CC = gcc
CFLAGS = -g -Wall

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

.PHONY: clean

clean:
	rm $(TARGET)
