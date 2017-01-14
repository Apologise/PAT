//这个问题和全排列相似
#include<cstdio>
#include<cmath>
#define maxn 10
int n,P[maxn],count  = 0;
bool hashTable[maxn];

void generateP(int index){
	//如果index=n+1.则表明这个方案可行
	if(index == n + 1){
		for(int i = 1; i <= n; ++i){
			printf("%d",P[i]);
		}
		count++;
		printf("\n");
		return ;
	}

	for(int i = 1; i <= n; ++i){
		if(hashTable[i] == false){
			bool flag = true;
			for(int pre = 1; pre < index; ++pre){
				if(abs(pre - index) == abs(i - P[pre])){
					flag = false;
					break;
				}
			}
			if(flag){
				P[index] = i;
				hashTable[i] = true;
				generateP(index + 1);
				hashTable[i] = false;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	generateP(1);
	printf("%d\n", count);
	return 0;
}