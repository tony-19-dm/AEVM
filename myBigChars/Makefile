CC = gcc
CFLAGS = -Wall -Werror -Iinclude -I ../include
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

LIBNAME = libmybigchars.a

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o *.a
