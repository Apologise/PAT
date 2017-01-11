#include<cstdio>

int main(){
	int A,B,D;
	int ans[30];
	int index = 0;
	scanf("%d%d%d", &A,&B,&D);
	int x = A +B;
	do{
		ans[index++] = x % D;
		x = x / D;
	
	}while(x != 0);
	for(int i = index - 1; i >= 0; i--){
		printf("%d",ans[i]);
	}
	return 0;
}