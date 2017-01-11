#include<stdio.h>

int main(){
	int buf[200];
	int n,x;
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%d",&buf[i]);
		}
		scanf("%d", &x);
		int j;
		for( j = 0; j < n; ++j){
			if(x == buf[j]){
				printf("%d\n",j);
				break;
			}
		}
		if(j == n){
			printf("-1");
		}
	}
}