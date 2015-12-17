INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: containsDuplicate 

containsDuplicate.o: containsDuplicate.cpp ${HEADERS}

	${CXX} -c ${CFLAGS} ${INCS} $<

containsDuplicate: containsDuplicate.o 
	${CXX} -o $@ containsDuplicate.o ${LDFLAGS}

clean:
	rm -f *.o containsDuplicate
	
