#include<cstdio>
#define maxn 1000001
int N,M;
bool isPrime[maxn] = {false};
int pNum = 0;
int main(){
	scanf("%d%d",&N,&M);
	for(int i = 2;; ++i){
		if(isPrime[i] == false){
			pNum ++;
			if(pNum >= N && pNum <= M){
				printf("%d",i);
				if(pNum < M && (pNum - N +1) % 10 != 0 ){
					printf(" ");
				} else{
					printf("\n");
				}
			
			}else if(pNum > M){
			break;}
			for(int j = i + i; j < maxn; j += i){
				isPrime[j] = true;
			}
		}
	}
	return 0;
}