INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: deleteNode 

deleteNode.o: deleteNode.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

deleteNode:deleteNode.o 
	${CXX} -o $@ deleteNode.o ${LDFLAGS}

clean:
	rm -f *.o deleteNode 
