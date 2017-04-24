
CFLAGS=-g
LDFLAGS=-ldl
CXXFLAGS=-fPIC

all: main hello.la

main: main.c

hello.la: hello.o
	g++ -shared -fPIC -o $@ $<

