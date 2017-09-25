CFLAGS = -ansi -Wall -Wno-unused-result -pedantic -O2 -lm
DEPS = list.h queue.h
OBJ = ep5.o list.o queue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ep5: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm ep5


