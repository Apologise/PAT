#include<stdio.h>

int main(){
	char N[1000];
	scanf("%s",N);
	int count[10]={0};
	for(int i = 0; N[i] != '\0'; ++i){
		int index = N[i] - '0';
		count[index]++;
	}
	for(int i = 0; i < 10; ++i){
		if(count[i] != 0){
			printf("%d:%d\n",i,count[i]);
		}
	}
	return 0;
}