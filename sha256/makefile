SOURCE = driver.c
TARGET = sha256
DEPS = ../modules/bit_util.c ../modules/file_util.c ../modules/mem_util.c ./sha256.c
CC = gcc
CFLAGS = -g -Wall

run: $(TARGET)
	./$(TARGET) $(FILE)

$(TARGET): $(SOURCE) $(DEPS)
	$(CC) $(CFLAGS) $(SOURCE) $(DEPS) -o $(TARGET)

.PHONY: clean

clean:
	rm $(TARGET)