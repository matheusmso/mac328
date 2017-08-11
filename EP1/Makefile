CFLAGS = -ansi -Wall -Wno-unused-result -pedantic -O2
DEPS = GRAPH.h
OBJ = ep1.o matrix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ep1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm ep1


