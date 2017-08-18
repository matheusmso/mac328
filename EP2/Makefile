CFLAGS = -ansi -Wall -Wno-unused-result -pedantic -O2
DEPS = matrix.h
OBJ = ep2.o matrix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ep2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm ep2


