CC = gcc
CFLAGS = -Wall -Werror -Iinclude -I ../include
SRC = $(wildcard *.c) #возвращает все файлы с расширением .c в директории
OBJ = $(SRC:.c=.o) #возвращает все файлы с расширением .o

LIBNAME = libconsole.a

all: $(LIBNAME)

$(LIBNAME): $(OBJ) #создание статической библиотеки
	ar rcs $@ $^   

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o *.a
