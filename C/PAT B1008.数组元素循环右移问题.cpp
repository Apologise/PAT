/*
Author:Apolo
Time : 2017-01-14 
Problem Description��123456--����2Ϊ-->561234 
Method����1234ת�ã�56ת�ã�Ȼ������ת�� 
��˼��˼�����ⲻ���ܣ����M(���Ƶ�λ������Ԫ�صĸ�������ôҪȡ��) ,���һ��Ҫע�⣡������ 
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