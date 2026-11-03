
CC = gcc
CFLAGS = -Wall -Wextra -pthread -Isrc
TARGET = sync_car

all: $(TARGET)

$(TARGET): src/sync_car.c src/sync_car.h tests/sync_car-runner.c
	$(CC) $(CFLAGS) src/sync_car.c tests/sync_car-runner.c -o $(TARGET)

clean:
	rm -f $(TARGET) sync_car.o

.PHONY: all clean
