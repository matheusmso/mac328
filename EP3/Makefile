CFLAGS = -ansi -Wall -Wno-unused-result -pedantic -O2 -lm
DEPS = matrix.h
OBJ = ep3.o matrix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ep3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm ep3


