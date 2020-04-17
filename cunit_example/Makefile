#INC=-I./CUnit/include/
#LIB=-L./CUnit/lib/

all: CUnitExample.c
	gcc -o test $(INC) $(LIB) -lcunit $^

clean:
	-rm -rf *.o test *.txt

#run:
#	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./CUnit/lib/ ./test
