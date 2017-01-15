#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;

bool isPrime[maxn] ={0};
int prime[maxn],pNum = 0;

void findPrime(int n){
	for(int i = 2; i < n + 1; ++i){
		if(isPrime[i] == false){
			prime[pNum++] = i;
			for(int j = i+i; j < n + 1; j += i){
				isPrime[j] = true;
			}
		}	
	}	
} 

int main(){
	int N;
	scanf("%d", &N);
	findPrime(N);
	for(int i = 0; i < pNum; ++i){
		printf("%d ",prime[i]);
	}
	return 0;
}