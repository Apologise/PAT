#include<cstdio>
#include<cmath>
const int maxn = 10;	//最多为maxn个皇后
int n,count = 0;	//n个皇后
int P[maxn],hashTable[maxn] = {0};

//index表示列数，P[index] = k，表示第index列上皇后在第K行
void generateP(int index){
	if(index == n+1){
		for(int i = 1; i <= n; ++i){	//输出摆放方法
			printf("%d",P[i]);
		}
		printf("\n");
		count ++;
		return ;
	}

	for(int i = 1; i <= n; ++i){
		if(hashTable[i] == 0){
			bool flag = true;
			for(int pre = 1; pre < index; ++pre){
				if(abs(index - pre) == abs(i - P[pre])){
					flag = false;
					break;
				}
			}
			if(flag){
				P[index] = i;
				hashTable[i] = 1;
				generateP(index +1);
				hashTable[i] = 0;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	generateP(1);
	return 0;
}