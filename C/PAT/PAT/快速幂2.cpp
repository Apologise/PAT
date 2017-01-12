#include<cstdio>
#define LL long long

LL binaryPow(LL a, LL b){
	if(b == 1){return 1;}
	if(b & 1){
		return a * binaryPow(a,b);
	}else{
		LL mul = binaryPow(a, b / 2);
		return mul * mul;
	}
}