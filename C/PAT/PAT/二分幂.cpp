#define LL long long

LL binaryPow(LL a, LL b){
	if(b == 0){return 1;}
	if( b & 1){
		return a * binaryPow(a, b-1);
	}else{
		LL half = binaryPow(a, b / 2);
		return half * half;
	}
}