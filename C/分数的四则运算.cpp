/*
Author:Apolo
Time : 2017-01-14 
Problem Description：分数的表示和化简 
Method；由于分数的乘法和除法过程中可能使分子或分母超过int型表示范围，因此一般情况下
		，分子和分母应当使用long long存储 
*/
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;

struct Fraction{
	int up, down;
};

//分数的化简
Fraction reduction(Fraction result){
	if(result.down < 0){
		result.up = - result.up;
		result.down = - result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up, abs(result.down)));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

//分数的加法 
Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down + f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}

//分数的减法
Fraction sub(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down - f2.up*f1.down;
	result.down = f1.down*f2.down;
	return reduction(result);
}

//分数的乘法
Fraction mul(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);	
}

//分数的除法
Fraction divide(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);	
}

//分数的输出 
1.如果分母为1，那么直接输出分子
2.如果分子的绝对值大于分母，则为假分数，将分子除以分母整数，余数为分子 
3.直接照样输出 
void showResult(Fraction r){
	if(r.down == 1){
		printf("%lld",r.up);
	} else if(abs(r.up) > r.down){	//	化简的时候如果分母为负，将负号换上去，所以不需要求绝对值 
		printf("%d %d/%d", r.up, abs(r.up) % r.down, r.down);
	}else{
		printf("%d/%d", r.up, r.down);
	}
} 
 

