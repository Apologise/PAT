#include<stdio.h>
#include<string.h>

int main(){
	int  a, b;
	char result_temp[100], result[100];
	scanf("%d %d", &a, &b);
	sprintf(result, "%d", a+b);
	int len = strlen(result);
	int count = 0, j = 0;
	for(int i = len-1; i >= 0;){
		if(count == 3){
			result[j++] = ',';
			count = 0;
		}else{
			result[j++] = result_temp[i];
			count++;
			i--;
		}
	}
	result[j] = '\0';
	printf("%s", result);
	return 0;
} 
