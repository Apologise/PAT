#include<stdio.h>

int main(){
	int h;	//ÌÝÐÎµÄ¸ß
	scanf("%d", &h);
	int j = 0;
	for(int i = 0; i < h; ++i){
		for( j = 0; j < (h-1-i) * 2; ++j){
			printf(" ");
		}
		for(; j < (h+1) * 2; j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}