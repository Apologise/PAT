#include<cstdio>

const int maxn = 100;
char S[maxn][5],temp[5];

int hashTable[26*26*26+10];	//	因为是3个字母

int hashFun(char str[], int len){
	int id = 0;
	for(int i = 0; i < len; ++i){
		id = id * 26 + (str[i] - 'A');
	}
	return id;
}

int main(){
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s",S[i]);
		int id = hashFun(S[i],3);
		hashTable[id]++;
	}
	for(int i = 0; i < n; ++i){
		scanf("%s",temp);
		int id = hashFun(temp,3);
		printf("%d\n",hashTable[id]);
	}
	return 0;
}