INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: sametree

sametree.o: sametree.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

sametree: sametree.o 
	${CXX} -o $@ sametree.o ${LDFLAGS}

clean:
	rm -f *.o sametree
