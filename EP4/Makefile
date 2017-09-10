CFLAGS = -ansi -Wall -Wno-unused-result -pedantic -O2 -lm
DEPS = list.h bridge.h
OBJ = ep4.o list.o bridge.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ep4: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	rm ep4


