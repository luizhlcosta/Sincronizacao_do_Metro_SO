
CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = sync_car

all: $(TARGET)

$(TARGET): src/sync_car.c
	$(CC) $(CFLAGS) src/sync_car.c -o $(TARGET)

clean:
	rm -f $(TARGET) sync_car.o

.PHONY: all clean
