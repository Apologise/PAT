/*
Author:Apolo
Time : 2017-01-14
Problem Description：计算分数的和 
Method；定义结构体和分数加法运算 ,注意在分数加法中两数相乘可能超过int 
*/

#include<cstdio>

#include<algorithm>
#define LL long long
struct Fraction{
	LL up,down;
};

//求最大公约数
int gcd(LL a, LL b){
	if(b == 0){ 
		return a;
	}else {
		return gcd(b, a % b);
	} 
} 

//分数化简
Fraction reduction(Fraction f){
	if(f.down < 0){
		f.down = - f.down;
		f.up = -f.up;
	}
	if(f.up == 0){
		f.down = 1;
	}else{
		int d = gcd(abs(f.up),abs(f.down));
		f.up /= d;
		f.down /= d;
	}
	return f;	
} 

Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up * f2.down + f2.up*f1.down;
	return reduction(result);	
}

Fraction resultShow(Fraction result){
//	result = reduction(result);
	if(result.down == 1){
		printf("%lld", result.up);
	}else if(abs(result.up) > result.down){
		printf("%lld %lld/%lld\n", result.up/result.down,abs(result.up)%result.down, result.down);
	}else{
		printf("%lld/%lld\n",result.up,result.down);	
	}
}


int main(){
	Fraction result,temp;
	result.up = 0;
	result.down = 1;
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%lld/%lld", &temp.up,&temp.down );
	
		result  = add(result, temp);
	}
	resultShow(result);
	return 0;	
}
 