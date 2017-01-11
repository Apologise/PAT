#include<stdio.h>

int main(){
	char s[2][100];
	int a,b;
	scanf("%s",s[0]);
	scanf("%d",&a);
	scanf("%s",s[1]);
	scanf("%d",&b);

	int resultA = 0;
	for(int i = 0; s[0][i] != '\0'; ++i){
		int temp = s[0][i] - '0';
		if( temp == a){
			resultA = resultA*10 + a;
		}	
	}

	int resultB = 0;
	for(int i = 0; s[1][i] != '\0'; ++i){
		int temp = s[1][i] - '0';
		if( temp == b){
			resultB = resultB*10 + b;
		}	
	}

	printf("%d", resultA+resultB);
	//Test:resultA
	/*printf("%d", resultA);*/
}