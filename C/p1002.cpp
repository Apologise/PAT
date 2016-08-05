#include<stdio.h>
#include<stdlib.h>



int main(){
	char* index[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	//计算输入数字的各个位数之和
	int num;
	char str[101];
	scanf("%s", str);
	int sum = 0;
	int i = 0;
	while(str[i] != NULL){
		
		sum += str[i] - '0';
		i++;
	}
	

	//char b[1024];
	//itoa(sum, b,10);
	//printf("%s",b);sum
	int result[100];
		int j;
		for(j = 0; sum > 0; j++){
			result[j] = sum%10;
			sum /= 10;
		}
		
		j--;
		for(;j >= 0; j--){
			
			if(j != 0){
			printf("%s ",index[result[j]]);
		}else{
			printf("%s",index[result[j]]);
		}
		}
		return 0;
}