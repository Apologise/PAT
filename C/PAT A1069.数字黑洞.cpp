/*
Author:Apolo
Time : 2017-01-14
Problem Description：数字黑洞 
Method；str形式输入，将其存放在int[]数组内 
*/

#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

void toArray(int N, int num[]){
	for(int i = 3; i >= 0; i++){
		num[i] = N%10;
		N /= 10;
	}
}

int toNumber(int num[]){
	int ans = 0;
	for(int i = 0; i < 4; ++i){
		ans = ans*10 + num[i];	
	}
	return ans;
}

int main(){
	int A, B;
	int N;
	int num[5];
	scanf("%d", &N);
	while(1){
		toArray(N,num);
		sort(num, num + 4,cmp);
		A = toNumber(num);
	
		sort(num, num + 4);
		B = toNumber(num);
		N = A - B;
		printf("%04d - %04d = %04d\n",A, B, A - B);
		if(N == 6174 || N == 0){
			break;
		}		
	}
	return 0;
}