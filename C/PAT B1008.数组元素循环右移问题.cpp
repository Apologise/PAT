/*
Author:Apolo
Time : 2017-01-14 
Problem Description：123456--右移2为-->561234 
Method；将1234转置，56转置，然后整个转置 
反思：思考问题不缜密，如果M(右移的位数大于元素的个数，那么要取余) ,这个一定要注意！！！！ 
*/ 

#include<cstdio>
#define maxn 110

void reverse(int num[],int left, int right){
	int i = left, j = right -1;
	while(i < j){
		int temp = num[i];
		num[i] = num[j];
		num[j] = temp;
		i++;
		j--;
	}
}

int main(){
	int N,M;
	int num[maxn];
	scanf("%d%d",&N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}
	if(M-N > 0){
		M = M%N;
	}
	
	reverse(num,0,N - M);
	reverse(num, N-M, N);
	reverse(num,0,N);

	for(int i = 0; i < N; ++i){
		printf("%d",num[i]);
		if(i < N-1){
			printf(" ");
		}
	}
	return 0;
} 