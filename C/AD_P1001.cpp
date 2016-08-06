#include<stdio.h>

int main(){
	int a, b, c,flag = 0;
	/*
		temp用来存放大的数据，tot表示数组指针
	*/
	int temp[1001], index = 0;
	
	scanf("%d%d", &a, &b);
	c = a + b;
	if( c < 0){
		flag = -1;
		c = -c;
	}else if(c == 0){
		printf("0");
	}
	
	while( c != 0 ){
		temp[index++] = c%10;
		c /= 10;
	}

	
	//如果c为负数，那么先输出“-”
	if(flag == -1){ printf("-");}
	//按照规定的格式输出数字，注意每隔3位输出“，”,也就是说当该位的序号为3的倍数的要输","
	for( int i = index - 1; i >= 0 ; i--){
		printf("%d", temp[i]);
		if( i % 3 == 0 && i){ printf(",");}
	}
	printf("\n");
	return 0;
}