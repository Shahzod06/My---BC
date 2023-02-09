CC=gcc
CFLAGS= -Wall -Wextra -I.
DEPS = my_bc.h
OBJ = my_bc.c
TARGET = my_bc
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

fclean:
	rm -f ${TARGET} *.o