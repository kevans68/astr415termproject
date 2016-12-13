all: IV hw6

IV : 
	gcc -g -o randex randex.c nrutil.c
	
hw6:
	gcc -g -o hw6 hw6.c nrutil.c rk4.c Leapfrog.c -lm 
	
clean: 
	rm -f  randex hw6

