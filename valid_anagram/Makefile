INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: valid_anagram 

valid_anagram.o: valid_anagram.cpp ${HEADERS}

	${CXX} -c ${CFLAGS} ${INCS} $<

valid_anagram: valid_anagram.o 
	${CXX} -o $@ valid_anagram.o ${LDFLAGS}

clean:
	rm -f *.o valid_anagram
	
