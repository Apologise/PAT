/*
Author:Apolo
Time : 2017-01-14 
Problem Description：埃氏筛选法求素数 
Method；
*/

#include<cstdio>
#define maxn 100010

bool isPrime[maxn] ={false};
int prime[maxn] = {0},pNum = 0;
void func(){
	for(int i = 2; i < maxn; ++i){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = 2*i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
} 