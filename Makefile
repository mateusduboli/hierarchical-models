LDLIBS=-lm -lglut -lgl
LDFLAGS=-L'/usr/X11/lib'
CXXFLAGS=-I'/usr/X11/include'

TARGET=elephant

all: $(TARGET)

clean: 
	rm *.o $(TARGET)
