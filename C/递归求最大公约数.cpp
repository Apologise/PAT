/*
Author:Apolo
Time : 2017-01-14 
Problem Description：求最大公约数 
Method；递归求最大公约数，可以用定力证明a,b的最大公约数和b，a/b的最大公约数相等 ,另外如果
		0与ａ的最大公约数是a 
*/ 

int gcd(int a, int b){
	if(a == 0){
		return a;
	}else{
		return gcd(b, a % b);	//	将a,b交换 
	}	
} 

//最小公倍数是：ab/gcd(a,b) 
int lcm(int a, int b){
	return a*b/gcd(a,b);	//	为了防止int溢出，可以先进行除法运算，在乘，
	//return a/gcd(a, b)*b;,	//	因为a/gcd一定可以整除 
} 