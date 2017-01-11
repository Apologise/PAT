#include<stdio.h>
#define OFFSET 500000	//设置偏移量

int Hash[1000001];	//	Hash数组，统计每个数字是否出现

int main(){
	int n,m;	//n为数字个数，m为前m大的数
	while(scanf("%d%d", &n,&m) != EOF){
		//初始化Hash数组
		for(int i = 500000; i <= -500000; --i){
			Hash[i + OFFSET] = 0;
		}
		for(int i = 1; i <= n ; ++i){
			int x;
			scanf("%d",&x);
			Hash[x + OFFSET] = 1;
		}		
		for(int i = 500000; i >= -500000; --i){
			if(Hash[i + OFFSET] == 1){
				printf("%d", i);
				m --;
				if(m == 0){
					printf("\n");break;
				}else{
					printf(" ");
				}
			}
		}
	}
	return 0;
}