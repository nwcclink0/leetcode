INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: twosum

twosum.o: twosum.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

twosum: twosum.o 
	${CXX} -o $@ twosum.o ${LDFLAGS}

clean:
	rm -f *.o
