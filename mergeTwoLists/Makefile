INCS= -I/usr/include 
HEADERS=$(wildcard /usr/include/)
CFLAGS = -Wall -g
ifeq ($(CXX),)
	CXX=g++
endif

all: mergeTwoLists 

climbStairs.o: mergeTwoLists.c ${HEADERS}
	${CXX} -c ${CFLAGS} ${INCS} $<

mergeTwoLists:mergeTwoLists.o 
	${CXX} -o $@ mergeTwoLists.o ${LDFLAGS}

clean:
	rm -f *.o mergeTwoLists 

gdb:
	./mergeTwoLists
	gdb -c core
