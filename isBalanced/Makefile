INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)
CFLAGS = -Wall -g
ifeq ($(CXX),)
	CXX=g++
endif

all: isBalanced 

isBalanced.o: isBalanced.c ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

isBalanced: isBalanced.o
	${CXX} -o $@ isBalanced.o ${LDFLAGS}

clean:
	rm -f *.o isBalanced.o

gdb:
	./isBalanced
	gdb -c core
