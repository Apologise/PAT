/*
Author:Apolo
Time : 2017-01-14
Problem Description������һ����N,��0~N��1���ֵĸ��� 
Method���ӵ͵��ߣ��ֱ�����ÿһλȡ1ʱ������ ,���㵱ǰλ����ߵ��������ұߵ��� 
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