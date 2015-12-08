INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: reverseList 

reverseList.o: reverseList.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

reverseList: reverseList.o
	${CXX} -o $@ reverseList.o ${LDFLAGS}

clean:
	rm -f *.o
