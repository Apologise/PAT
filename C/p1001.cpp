#include<stdio.h>

int main(){
	int steps = 0;
	int num;
	scanf("%d",&num);
	
		while(num > 1){
			if(num%2 == 0){
				num /= 2; 
				steps ++;
			}else{
				num = (3*num+1)/2;
				steps ++;
			}
		}
		printf("%d", steps);
	}


	