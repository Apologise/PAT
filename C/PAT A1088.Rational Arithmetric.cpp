/*
Author:Apolo
Time : 2017-01-14
Problem Description：实现分数的四则运算 
Method；
*/
#include<cstdio>
#include<algorithm> 
#define LL long long
using namespace std;

struct Fraction{
	LL up, down;
};

LL gcd(LL a, LL b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

Fraction reduction(Fraction result){
	if(result.down < 0){
		result.down = - result.down;
		result.up = -result.up;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		LL d = gcd(abs(result.up), abs(result.down));
		result.up = result.up / d;
		result.down = result.down / d;
	}
	return result;
}
Fraction add(Fraction a, Fraction b){
	Fraction result;
	result.up = a.up * b.down + b.up * a.down;
	result.down = a.down*b.down;
	return reduction(result);
}

Fraction sub(Fraction a, Fraction b){
	Fraction result;
	result.up = a.up * b.down - b.up * a.down;
	result.down = a.down * b.down;
	return reduction(result);
}

Fraction mul(Fraction a, Fraction b){
	Fraction result;
	result.up = a.up * b.up;
	result.down = b.down * a.down;
	return reduction(result);
}

Fraction div(Fraction a, Fraction b){
	Fraction result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	return reduction(result);
}

Fraction showResult(Fraction result){
	result = reduction(result);
	if(result.up < 0){
		printf("(");
	}
	if(result.down == 1){
		printf("%lld",result.up);
	}else if(abs(result.up)> abs(result.down)){	//	当有假分数时 
		printf("%lld %lld/%lld",result.up / result.down, abs(result.up) % result.down, result.down);
	}else{
		printf("%lld/%lld",result.up, result.down);
	}		
	if(result.up < 0){
		printf(")");
	}
}

int main(){
	Fraction a,b;
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);

	//加法
	showResult(a);

	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a,b));
	printf("\n"); 
	//减法
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a,b));
	printf("\n"); 
	//乘法
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(mul(a,b)); 
	printf("\n"); 
	//除法
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up == 0){
	printf("Inf");
	} else{
		showResult(div(a,b));
	}
	return 0;
}