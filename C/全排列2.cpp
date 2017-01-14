#include<cstdio>
#define maxn 10

int n,P[maxn] = {0};
//����һ��hashTable���ж���������Ƿ��Ѿ�ʹ�ù�
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

