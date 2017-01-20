/*
Author:Apolo
Time : 2017-01-15 
Problem Description：高精度的加法运算 
Method；利用字符串输入高精度数，然后用结构体保存 
反思：注意，使用memset要添加头文件string.h 
*/
#include<cstdio>
#include<cstring>
struct bign{
	int d[1000];
	int len;
	bign(){
		len = 0;
		memset(d,0,sizeof(d));
	}
}; 

bign strToBign(char str[]){
	bign a;
	int len = strlen(str);
	a.len = len;
	for(int i = 0; i < len; ++i){
		a.d[i] = str[len - i - 1] - '0';
	}
	return a;
}

bign add(bign a, bign b){
	bign result;
	int carry = 0;	//进位
	for(int i = 0; i < a.len || i < b.len; ++i){
		int temp = a.d[i] + b.d[i] + carry;
		carry = temp / 10;
		result.d[result.len++] = temp % 10; 
	} 
	if(carry != 0){
		result.d[result.len++] = carry;	
	}
	return result;
}

bign sub(bign a, bign b){
	bign result; 
	for(int i = 0; i < a.len || b.len; i++){
		if(a.d[i] < b.d[i]){
			a.d[i+1]--;
			a.d[i] += 10;
		}
		result.d[i] = a.d[i] - b.d[i];		
	}
	while(result.len - 1 >= 1 && result.d[result.len - 1] == 0){
		result.len--;
	}
	return result;
}

bign div(bign a, int b){
	bign result;
	int carry;
	for(int i = 0; i < a.len; i++){
		int temp = a.d[i]*b + carry;
		result.d[i] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		result.d[result.len ++] = carry % 10;
		carry /= 10; 
	}
	return result;
}

bign div(bign a, int b, int &r){	//	因为可能不能被整除，所以需要保留余数
	bign result;
	result.len = a.len;
	for(int i = a.len- 1; i >= 0; i--){
		r = r * 10 + a.d[i];
		if(r < b){
			result.d[i] = 0;
		}else{
			result.d[i] = r / b;
			r = r % b;
		}
	}
	while(result.len - 1 >= 1 && result.d[result.len - 1] == 0){
		result.len --;
	}
	return result;
	
}
void print(bign a){
	
	for(int i = a.len - 1; i >= 0;--i){
		printf("%d", a.d[i]);
	}
}

int main(){
	char str1[1000], str2[1000];
	scanf("%s%s",str1, str2);
	bign a = strToBign(str1);
	bign b = strToBign(str2);
	print(add(a,b));
	return 0;
}