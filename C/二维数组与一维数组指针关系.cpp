#include<stdio.h>

int main(){
	int i, j, a[4][5], (*p)[5];
	p = a;
	for(i = 0;  i < 4; ++i){
		for(j = 0; j < 5; ++j){
			*(*(p+i)+j) = i*3+j+1;
		}
	}
	for(i = 0;  i < 4; ++i){
		for(j = 0; j < 5; ++j){
			printf("%d ", *(*(p+i)+j));
		}
	}
	 
	return 0;
} 
