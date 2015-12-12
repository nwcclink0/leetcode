INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: invertbinrarytree 

invertbinvrarytree.o: invertbinrarytree.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

invertbinrarytree: invertbinrarytree.o 
	${CXX} -o $@ invertbinrarytree.o ${LDFLAGS}

clean:
	rm -f *.o invertbinrarytree 
