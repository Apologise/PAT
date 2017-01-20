/*
Author:Apolo
Time : 2017-01-15
Problem Description£º´óÊý³ý·¨ 
Method£»
*/

#include<cstdio>
#include<cstring>



struct dign{
	int len;
	int d[1010];
	dign(){
		memset(d,0, sizeof(d));
	}
}; 

dign change(char str[]){
	dign result;
	result.len= strlen(str);
	for(int i = 0; i < result.len; i++){
		result.d[i] = str[result.len - i -1] - '0';
	}
	return result;
}

void print(dign a){
	for(int i = a.len -1; i >= 0; --i){
		printf("%d", a.d[i]);
	}
}

dign div(dign a, int b, int &r){
	dign result;
 	result.len = a.len;
	for(int i = a.len-1; i >= 0; --i){
		r = r * 10 + a.d[i];
		if(r < b){
			result.d[i] = 0;
		}else{
			result.d[i] = r / b;
			r = r % b;
		}
	}
	while(result.len - 1 >= 1 && result.d[result.len - 1] == 0){
		result.len--;
	}
	return result;
}

int main(){
	char str[1010];
	int Q,R;
	scanf("%s %d", str, &Q);
	dign A = change(str);
	print(div(A,Q,R));
	printf(" %d",R);
	return 0;

}
