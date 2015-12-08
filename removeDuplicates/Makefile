INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: removeDuplicate

removeDuplicate.o: removeDuplicate.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

removeDuplicate: removeDuplicate.o
	${CXX} -o $@ removeDuplicate.o ${LDFLAGS}

clean:
	rm -f *.o
