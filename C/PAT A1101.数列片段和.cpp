/*
Author:Apolo
Time : 2017-01-14 
Problem Description�������е��жϺ� 
Method�������һλ���ֵ��ܵĳ��ִ��� 
*/ 

#include<cstdio>

int main(){
	int N;
	double ans = 0, x;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%lf", &x);
		ans += x*i*(n + 1 - i); 
	}
	printf("%.2f",ans);
	return 0;
}