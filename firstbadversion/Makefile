INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: firstbadversion 

firstbadversion.o: firstbadversion.cpp ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

firstbadversion: firstbadversion.o 
	${CXX} -o $@ firstbadversion.o ${LDFLAGS}

clean:
	rm -f *.o firstbadversion
