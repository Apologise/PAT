#include<stdio.h>
void add(double , double, double *);

int  main(){
	double a = 5.5, b = 1.1, c = 0;
	add(a, b, &c);
	printf("%f", c);
	return 0; 
}

void add(double m, double n, double *q){
	*q = m+n;
}
