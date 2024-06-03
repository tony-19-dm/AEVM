CC = gcc
CFLAGS = -Wall -Werror -Iinclude -I include
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: bin/app

r: 
	$(MAKE)
	./bin/app

bin/app: console/test.c ./myReadkey/libmyreadkey.a ./mySimpleComputer/libmysimplecomputer.a ./console/libconsole.a ./myALU_CU/libmyALUCU.a ./myTerm/libmyterm.a ./myBigChars/libmybigchars.a 
	$(CC) $(CFLAGS) -o $@ $^

./myTerm/libmyterm.a: ./myTerm/*.c
	$(MAKE) -C myTerm/

./mySimpleComputer/libmysimplecomputer.a: ./mySimpleComputer/*.c 
	  $(MAKE) -C mySimpleComputer/

./console/libconsole.a: ./console/*.c
	  $(MAKE) -C console/

./myBigChars/libmybigchars.a: ./myBigChars/*.c
	  $(MAKE) -C myBigChars/

./myReadkey/libmyreadkey.a: ./myReadkey/*.c
	  $(MAKE) -C myReadkey/

./myALU_CU/libmyALUCU.a: ./myALU_CU/*.c
	  $(MAKE) -C myALU_CU/

.PHONY: clean

clean:
	$(MAKE) -C console clean
	$(MAKE) -C mySimpleComputer clean
	$(MAKE) -C myTerm clean
	$(MAKE) -C myBigChars clean
	$(MAKE) -C myReadkey clean
	$(MAKE) -C myALU_CU clean

