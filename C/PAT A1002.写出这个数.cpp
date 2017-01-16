/*
Author:Apolo
Time : 2017-01-14 
Problem Description：计算一个自然数的所有位数之和 
Method；
*/ 

#include<cstdio>
#define maxn 110

char num[10][5] = {
"ling","yi","er","san","si","wu","liu","qi","ba","jiu"	};

int main(){
	char str[maxn];
	scanf("%s", str);
	int ans = 0;
	for(int i = 0; str[i]; ++i)	{
		ans += str[i] - '0';
	}
	int result[5],index = 0;
	if(ans == 0){
		printf("ling\n");
	}else{
	for(int i = 0 ; ans !=0; ++i){
		result[index++] = ans % 10;
		ans /= 10;			
	}
	for(int i = index -1; i >= 0; --i){
		printf("%s",num[result[i]]);
		if(i > 0){
			printf(" ");
		}
	}
	}
	return 0;
	
	
} 