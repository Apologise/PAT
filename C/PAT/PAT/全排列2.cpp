#include<cstdio>
#define maxn 10

int n,P[maxn] = {0};
//定义一个hashTable来判断这个数字是否已经使用过
bool hashTable[maxn];

void generateP(int index){
	if(index == n + 1){
		for(int i = 1; i <= n; ++ i){
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}

	for(int i = 1; i <= n; ++i){
		if(hashTable[i] == false){
			P[index] = i;
			hashTable[i] = true;
			generateP(index+1);
			hashTable[i] = false;
		}
	}
}

int main(){
	scanf("%d", &n);
	generateP(1);
	return 0;
}

