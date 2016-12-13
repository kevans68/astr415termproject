all: IV hw6 galaxy

IV : 
	gcc -g -o randex randex.c nrutil.c
	
hw6:
	gcc -g -o hw6 hw6.c nrutil.c rk4.c Leapfrog.c -lm 
	
galaxy:
	gcc -o galaxy Nbody_galaxy.c nrutil.c leapfrog.c rk4.c -O0 -lm
	
clean: 
	rm -f  randex hw6 galaxy

