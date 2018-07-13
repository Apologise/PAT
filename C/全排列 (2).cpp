#include<cstdio>
const int maxn = 10010;
int P[maxn];
bool hashtable[maxn] = {false};
int n;
void generate(int index){
	if(index == n+1){
		for(int i = 1; i <= n; ++i){
			printf("%d", P[i]);
		}
		printf("\n");
	}
	for(int i = 1; i <= n; ++i){
		if(hashtable[i] == false){
			P[index] = i;
			hashtable[i] = true;
			generate(index+1);
			hashtable[i] = false;
		}
	}
}

int main(){
	n = 4;
	generate(1);
	return 0;
}