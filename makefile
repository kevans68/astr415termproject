all: IV

IV : 
	gcc -g -o randex randex.c nrutil.c
	
clean: 
	rm -f  randex xy.dat 

