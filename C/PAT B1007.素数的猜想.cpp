/*
Author:Apolo
Time : 2017-01-14
Problem Description£º
Method£»ÇóËØÊý±í 
*/ 

#include<cstdio>
#include<cmath>
#define maxn 100010

int prime[maxn],pNum = 0; 

bool isPrime(int N){
	if(N == 1){
		return false;
	}else{
		int sqr = (int)sqrt(1.0*N); 
		for(int i = 2; i <= sqr; ++i){
			if(N % i == 0){
				return false;
			}
		}
	}
	return true;
}

void findPrime(int N){
	for(int i = 1; i <= N; ++i){
		if(isPrime(i)){
			prime[pNum++] = i;
		}
	}
}

int main(){
	int N,count = 0;
	scanf("%d", &N);
	 
	findPrime(N);
	for(int i = 1; i < pNum; ++i){
		if(prime[i] - prime[i-1] == 2){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
} 