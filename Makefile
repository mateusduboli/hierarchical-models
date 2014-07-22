LDFLAGS= -L'/usr/X11/lib'
CFLAGS= -I'/usr/X11/include'

LDLIBS= -lm -lglut -lglu -lgl
CFLAGS+= -I'include'
TARGET=model

vpath %.c src

all: $(TARGET)

${TARGET}: movement.o elephant.o

run: all
	./$(TARGET)

clean: 
	rm -rf *.o $(TARGET)
