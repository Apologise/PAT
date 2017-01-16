/*
Author:Apolo
Time : 2017-01-14
Problem Description：输入一个数，及该数的进制，判断该数和该逆转的数是否是素数 
Method；
*/

#include<cstdio>
#include<cmath>
#define maxn 100010
bool isPrime(int N){
	if(N == 1){
		return false;
	}else{
		int sqr = (int)sqrt(1.0*N);
		for(int i = 2; i <= sqr; ++i){
			if(N % i == 0){
				return false;
			}
		}
	}
	return true;
}
int d[maxn];
int main(){
	int n,radix;
	while(scanf("%d", &n) != EOF){
		if(n < 0){break;}
		scanf("%d", &radix);
		if(isPrime(n) == false){
			printf("No\n");
		}else{
			//将N转为radix进制的数放入数组并逆转
			int index = 0;
			do{
				d[index++] = n % radix;
				n /= radix;
			}while(n != 0);
			//将这个数组逆转表示为十进制
			int ans = 0;
			for(int i = 0; i < index; ++i){
				ans = ans * radix + d[i];
			}
			if(isPrime(ans)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}	
		}
	}
	return 0;
}