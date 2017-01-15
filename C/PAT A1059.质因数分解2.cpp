/*
Author:Apolo
Time : 2017-01-15 
Problem Description：
Method；输入为N,首先求素数表，在素数和N的开方下循环，然后如果该数能被该素数整除，那么先求出该素数的个数，
		N不断缩小，然后如果最后N == 1退出循环，如果不等于1那么最后的N是最后一个质因数 
*/

#include<cstdio>
#include<cmath>
#define maxn 100010

bool isPrime(int n){
	if(n == 1){return false;}
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2; i <= sqr; ++i){
		if(n % i == 0){
			return false;
		}
	}
	return true; 
} 

int prime[maxn],pNum = 0;
void findPrime(){
	for(int i = 1; i < maxn; ++i){
		if(isPrime(i)){
			prime[pNum++] = i;
		}
	}
}

struct Factor{
	int x, cnt;
};

int main(){
	int N;
	Factor fac[10];
	findPrime();
	scanf("%d", &N);
	if(N == 1){
		printf("1=1\n");
	}else{
		printf("%d=", N);
	int sqr = (int)sqrt(1.0*N), num = 0;
	for(int i = 0; i < pNum && i <= sqr; ++i){
		if(N % prime[i] == 0){
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			//计算该质因数的个数
			while(N % prime[i] == 0){
				fac[num].cnt++;
				N /= prime[i];
			}		
			num ++;
		}
		if(N == 1){break;}
	}
	if(N != 1){
		fac[num].x = N;
		fac[num++].cnt = 1;  
	}
	
	for(int i = 0; i < num; ++i){
		if(i > 0){
			printf("*");
		}
		printf("%d", fac[i].x);
		if(fac[i].cnt >1){
			printf("^%d",fac[i].cnt);
		}
		}
	}
	return 0;
}