CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCS = horaireTrain.c
OBJS = $(SRCS:.c=.o)
EXEC = horaireTrain

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
