/*
Author:Apolo
Time : 2017-01-14
Problem Description：输入一个不超过20位的数，且每个位范围是1-9并且不重复，然后将这个数乘以2，判断这个数是否依然是其排列 
Method；
*/ 

#include<cstdio>
#include<cstring>

int count[10] = {0};
struct bign{
	int len;
	int d[30];
	bign(){
		len = 0;
		memset(d, 0, sizeof(d));
	}
};

bign mul(bign a, int b){
	bign result;
	result.len= a.len;
	int carry = 0;;
	for(int i = 0; i < a.len; i++){
		int temp = a.d[i]*b + carry;
		result.d[i] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		result.d[result.len++] = carry % 10;
		carry /= 10;		
	}
	return result;
}

bign changeToBign(char str[]){
	bign result;
	result.len = strlen(str);
	for(int i = 0; i <result.len ; i++){
		result.d[i] = str[result.len - i - 1] - '0';
		count[result.d[i]] ++;
	}
	return result;
}

void print(bign result){
	for(int i = 0; i < result.len; i++){
		printf("%d",result.d[result.len - i -1]);
	}
	
}

bool isEqual(bign a, bign b){
	if(a.len != b.len){
		return false;
	}else{
		for(int i = 0; i < b.len; i++){
			count[b.d[i]] --;
		}
		for(int i = 0; i < 10; i++){
			if(count[i] != 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	char str[30];
	scanf("%s",str);
	bign A = changeToBign(str);
	bign B = mul(A,2);
	if(isEqual(A,B)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	print(B);
	return 0;		
}