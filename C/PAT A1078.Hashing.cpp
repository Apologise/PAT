/*
Author:Apolo
Time : 2017-01-14
Problem Description：Hashing算法 H(key) = key MOD M; M 为大于等于表长的最小素数 
Method；
*/
#include<cstdio>
#include<cmath>
bool isPrime(int N){
	if(N == 1){
		return false;
	}
	int sqr = (int)sqrt(1.0*N);
	for(int i = 2; i <= sqr; ++i){
		if(N % i == 0){
			return false;
		}
	}
	return true;
}

int findPrime(int N){
	for(int i = N;;++i){
		if(isPrime(i)){
			return i;
		}
	}
	return N;
}
int main(){
	int MSize, N,x,result[10010],index = 0,TSize;
	bool hashTable[10010] = {0};
	scanf("%d %d",&MSize, &N);
	TSize = findPrime(MSize);
	for(int i = 0; i < N; ++i){
		scanf("%d",&x);
		int M = x % TSize;
		if(hashTable[M] == false){
			hashTable[M] = true;
			result[index++] = M;
		}else{
			int step; //二次探查法步长
			for(step = 1; step < TSize; ++step){
				M = (x + step * step) % TSize;
				if(hashTable[M] == false){
					hashTable[M] = true;
					result[index++] = M;
					break;
				}
			}
			if(step >= TSize){
				result[index++] = -1;
			} 
		}
	}
	for(int i = 0; i < index; ++i){
		if(result[i] >= 0){
			printf("%d",result[i]);
		}else{
			printf("-");
		}
		if(i < index - 1){
			printf(" ");
		} 
		
	}
	return 0;
}