all: statTest.c
	gcc statTest.c -o stats  

clean:
	rm *~
	rm *.o

run:
	./stats
