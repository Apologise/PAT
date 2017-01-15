/*
Author:Apolo
Time : 2017-01-14
Problem Description：输入一个数N,求0~N中1出现的个数 
Method；从低到高，分别讨论每一位取1时的种数 ,计算当前位的左边的数，和右边的数 
*/

#include<cstdio>

int main(){
	
	int ans = 0, a = 1;
	int N, left ,right, now;
	scanf("%d", &N);
	while(N / a != 0){
		left = N / (a * 10);
		right = N % a;
		now = N / a % 10;
		if(now == 0){
			ans += left * a;
		}else if(now == 1){
			ans += left*a + 1 + right;
		}else{
			ans += (left+1)*a;
		}
		a *= 10;	
	}
	printf("%d\n",ans);
	return 0;
} 