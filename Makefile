LDLIBS= -lm -lglut -lgl
LDFLAGS= -L'/usr/X11/lib'
CFLAGS= -I'include' -I'/usr/X11/include'
TARGET=model

vpath %.c src

all: $(TARGET)

${TARGET}: movement.o wire_elephant.o 

run: all
	./$(TARGET)

clean: 
	rm -rf *.o $(TARGET)
