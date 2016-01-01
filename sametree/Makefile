INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)

ifeq ($(CXX),)
	CXX=g++
endif

all: climbStairs 

climbStairs.o: climbStairs.c ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

climbStairs: climbStairs.o
	${CXX} -o $@ climbStairs.o ${LDFLAGS}

clean:
	rm -f *.o climbStairs
