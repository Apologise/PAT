#include<stdio.h>


int main(){
	int N;
	scanf("%d",&N);
	int num[N];
	for(int i = 0; i < N; ++i){
		num[i] = i;
	}
	for(int i = 0; i < N; ++i){
		printf("%d ",num[i]);
	}
	return 0;
}