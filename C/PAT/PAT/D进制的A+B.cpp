#include<stdio.h>
#include<string.h>

int main(){
	int A,B,D;
	char result[100000];
	scanf("%d%d%d",&A,&B,&D);
	int E = A+B;
	int i = 0;
	if( E != 0){
	while( E != 0){
		result[i++] = E % D + '0';
		E = E / D;
	}
	
	result[i] = '\0';
	int n = strlen(result);
	for(int i = n-1; i >= 0; --i){
		printf("%c",result[i]);
	}
	}else{
		printf("0");
	}
	return 0;
}