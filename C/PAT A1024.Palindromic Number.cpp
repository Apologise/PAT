/*
Author:Apolo
Time : 2017-01-14
Problem Description£ºÅÐ¶Ï»ØÎÄÊý 
Method£»
*/

#include<cstdio>
#include<cstring>
#define maxn 1010

struct bign{
	int len;
	int d[maxn];
	bign(){
		len = 0;
		memset(d,0,sizeof(d));
	}
};

bign changeToBign(char str[]){
	bign result;
	result.len = strlen(str);
	for(int i = 0; i < result.len; i++){
		result.d[i] = str[result.len - i - 1] - '0';
	}
	return result;
}

bign add(bign a, bign b){
	bign result;
	int carry = 0;
	result.len = 0;
	for(int i = 0; i < a.len || i < b.len; ++i){
		int temp = a.d[i] + b.d[i] + carry;
		result.d[result.len++] = temp % 10;
		carry = temp / 10;	
	}
	if(carry != 0){
		result.d[result.len++] = carry;
	}
	return result;
}

void print(bign result){
	for(int i = result.len - 1; i >= 0; i--){
		printf("%d", result.d[i]);
	}
}

bool isPalindromic(bign a){
	int i = 0, j = a.len - 1;
	while(i < j){
		if(a.d[i] != a.d[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;	
}

bign reverse(bign a){
	bign result;
	result.len = 0;
	for(int i = a.len - 1; i >= 0; i--){
		result.d[result.len++] = a.d[i];
	}
	return result;
}

int main(){
	char str[1000];
	int K;
	scanf("%s%d",str, &K);
	bign N = changeToBign(str);
	int count = 0;
	bign temp;
	while(!isPalindromic(N) && count < K){
		temp = reverse(N);
		N = add(N, temp);
		count++;
	}
	print(N);
	printf("\n%d",count);
	return 0;
	
} 