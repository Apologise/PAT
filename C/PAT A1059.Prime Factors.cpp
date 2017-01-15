/*
Author:Apolo
Time : 2017-01-14
Problem Description：分解质因子 
Method；利用数素数的方法 
*/

#include<cstdio>
#include<cmath>
#define maxn 100010
struct Factor{
	int x,cnt;
};

bool isPrime(int n){
	if(n == 1){return false;}
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2; i <= sqr; i++){
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

Factor fac[10];
int main(){
	int N;
	findPrime();
	scanf("%d", &N);
	if(N == 1){
		printf("1=1");
	}else{
		printf("%d=",N);
		int sqr = (int)sqrt(1.0*N),num = 0;
		for(int i = 0; i < pNum && prime[i] <= sqr; i++){
			if(N % prime[i] == 0){
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(N % prime[i] == 0){
					fac[num].cnt++;
					N /= prime[i];
				}
				num++;
			}
			if(N == 1){
				break;
			}
		}
		if(N != 1){
			fac[num].x = N;
			fac[num++].cnt = 1;
		}
		
		for(int i = 0; i < num; i++){
			if(i > 0){printf("*");}
			printf("%d", fac[i].x);
			if(fac[i].cnt > 1){
				printf("^%d",fac[i].cnt);
			}
		}
	}
	return 0;
}