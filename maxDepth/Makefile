INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: maxDepth 

maxDapth.o: maxDepth.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

maxDepth: maxDepth.o 
	${CXX} -o $@ maxDepth.o ${LDFLAGS}

clean:
	rm -f *.o maxDepth
