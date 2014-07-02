LDLIBS=-lm -lglut -lgl
LDFLAGS=-L'/usr/X11/lib'
CXXFLAGS=-I'/usr/X11/include'
CFLAGS=-I'/usr/X11/include'

TARGET=main

all: $(TARGET)

main: elephant.o main.o

run: all
	./$(TARGET)

clean: 
	rm *.o $(TARGET)
