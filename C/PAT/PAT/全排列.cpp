#include<cstdio>
const int maxn = 11;
int hashTable[maxn] = {0};
int n,P[maxn];

void generateP(int index){
	if(index == n + 1){
		for(int i = 1; i <= n; ++i){
			printf("%d", P[i]);
		}
		printf("\n");
		return ;
	}

	for(int x = 1; x <= n; ++x){
		if(hashTable[x] == 0){
			P[index] = x;
			hashTable[x] = 1;
			generateP(index + 1);
			hashTable[x] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	generateP(1);
	return 0;
}