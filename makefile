all: IV hw6 galaxy

IV : 
	gcc -g -o randex randex.c nrutil.c
	
hw6:
	gcc -g -o hw6 hw6.c nrutil.c rk4_sa.c Leapfrog_sa.c -lm 
	
galaxy:
	gcc -o galaxy Nbody_galaxy_1.c nrutil.c leapfrog_sa.c rk4_sa.c -O0 -lm
	
clean: 
	rm -f  randex hw6 galaxy

