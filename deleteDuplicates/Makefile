INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: deleteDuplicates

deleteDuplicates.o: deleteDuplicates.c ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

deleteDuplicates: deleteDuplicates.o
	${CXX} -o $@ deleteDuplicates.o ${LDFLAGS}

clean:
	rm -f *.o deleteDuplicates 
