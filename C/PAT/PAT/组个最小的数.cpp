#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	char num[10];
	for(int i = 0; i < 10; ++i){
		scanf("%c",&num[i]);
		getchar();
	}

	char result[10];
	int  temp[10] = {0};
	int j = 0;
	for( j = 0; num[j] < 10; ++j){
		if(result[j] != '0'){
			temp[j] = result[j] - '0';
		}
	}
	int zero = 10 - j;
	sort(temp,temp+j);
	result[0] = temp[0] + '0';
	int index = 0;
	for(int i = 0; i < zero; ++i){
		result[i+1] = '0';
		index = i+2;

	}
	for(int i = 1; i < j; ++i){
		result[index+1+i] = temp[i]; 
	}

	printf("%s",result);
}