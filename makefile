CC=gcc
CFLAGS=-Wall -Werror -I include 
LDFLAGS=`sdl2-config --cflags --libs` -lSDL2_image

all:bomberman.x

%.x: *.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

*.o : src/*.c
	$(CC) $^ -c $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *~ *.o

realclean: clean
	rm -f *.xsd