#include<cstdio>
#include<cstring>
const int maxn = 10;
char P[maxn],str[80];
int hashTable[maxn] = {0}, temp_hashTable[maxn] = {0};
int len,sum = 0;
void generateP(int index){
	if(index == len){
		for(int i = 0; i <= len-1; ++i){
			printf("%c", P[i]);
		}
		sum ++;
		printf("\n");
		return;
	}

	for(int i = 0; i < len; ++i){
		if(temp_hashTable[str[i] - 'A'] > 0){
			P[index] = str[i];
			temp_hashTable[str[i] - 'A'] = temp_hashTable[str[i] - 'A'] - 1;
			generateP(index + 1);
			temp_hashTable[str[i] - 'A'] = hashTable[str[i] - 'A'];
		}
	}
}

int main(){
	scanf("%s",str);
	len = strlen(str);
	//初始化hashTable
	
	for(int i = 0; i < len; ++i){
		hashTable[str[i] - 'A'] += 1;
		temp_hashTable[str[i] - 'A'] += 1;
	}
	
	generateP(0);
	printf("一共有%d种\n",sum);
	return 0;
}