#include<cstdio>
#define maxn 600*800+10

int prime(int num[],int len){
	int main = num[0], count = 0;
	for(int i = 0; i < len; ++i){
		if(num[i] == main){
			count++;
		}else{
			count--;
		}
		if(count <  0){
			main = num[i];
			count = 0;
		}
	}
	//count = 0;
	//for(int i = 0; i < len; ++i){
	//	if(num[i] == main){
	//		count++;
	//	}
	//}
	return main;
}

int num[maxn];
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 0; i < M*N; ++i){
		scanf("%d",&num[i]);
	}
	printf("%d\n",prime(num,M*N));
	return 0;
}