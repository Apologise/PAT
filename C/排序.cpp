#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}
int main(){
	int N;
	int buf[10000];
	while(scanf("%d",&N) != EOF){
		for(int i = 0; i < N; ++i){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+N,cmp);
		for(int i = 0; i < N ; ++i){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}

	return 0;
}