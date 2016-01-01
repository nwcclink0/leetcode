INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)
CFLAGS = -Wall -g
ifeq ($(CXX),)
	CXX=g++
endif

all:  

sameStack.o: sameStack.o ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

sameStack: sameStack.o
	${CXX} -o $@ sameStack.o ${LDFLAGS}

clean:
	rm -f *.o sameStack.o 

gdb:
	./sameStack/
	gdb -c core
