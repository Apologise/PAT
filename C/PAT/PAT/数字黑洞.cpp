/*
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到

一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
例如，我们从6767开始，将得到

7766 - 6677 = 1089

9810 - 0189 = 9621

9621 - 1269 = 8352

8532 - 2358 = 6174

7641 - 1467 = 6174

... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。
输入描述:
输入给出一个(0, 10000)区间内的正整数N。


输出描述:
如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例,每行中间没有空行。注意每个数字按4位数格

式输出。
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

//自定义排序规则
bool cmpUpper(int x,int y){
	return x > y;
}

bool cmpLower(int x, int y){
	return x < y;
}

int convert(int x, int &A,int &B){
	int i = 0;
	int tmp = x;
	int resultA[4] = {0},resultB[4] = {0},result[4] = {0};
	while(x != 0){
		result[i++] = x % 10;
		x = x/10;
	}
	if( (result[0] == result[1]) && (result[0] == result[2]) &&
		(result[0] == result[3])){
		printf("%d - %d = 0000",tmp,tmp);
		return 0;
	}
		
	//调用C++sort函数

	sort(result,result+4,cmpUpper);
	A = result[0]*1000+result[1]*100+result[2]*10+result[3];
	sort(result,result+4,cmpLower);
	B = result[0]*1000+result[1]*100+result[2]*10+result[3];
	printf("%04d - %04d = %04d\n",A,B,A-B);
	
	return A - B;
}

int main(){
	int N;
	scanf("%d",&N);
	/*int  A[4],B[4],result[4],temp = 0;*/
	int A = 0, B = 0,temp = 0;
	temp = convert(N,A,B);
	if(temp != 0){
	while(temp != 6174){
		temp = convert(temp,A,B);
	}
	//convert(temp,A,B);
	}
	//Test:convert
	/*printf("%d %d",A,B);*/
	return 0;
}