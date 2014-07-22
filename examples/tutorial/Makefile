LDLIBS= -lm -lglut -lglu -lgl
LDFLAGS= -L'/usr/X11/lib'
CFLAGS= -I'include' -I'/usr/X11/include'
TARGET=main

vpath %.c src

all: $(TARGET)

${TARGET}:

run: all
	./$(TARGET)

clean: 
	rm -rf *.o $(TARGET)
