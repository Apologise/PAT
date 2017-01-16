/*
Author:Apolo
Time : 2017-01-14
Problem Description£º
Method£»
*/

#include<cstdio>

int num[10000010] = {0},index = 0,count;

void numArray(int N,int num[]){
	if(N < 0){
		N = -N;
	}
	for(int i = 0; ; i++){
		num[index++] = N % 10;
		N /= 10; 
		count++;
		if(count % 3 == 0){
			num[index++] = -1;
		}
		if(N == 0){
			break;
		}
	}
}



int main(){
	int A,B,C;
	scanf("%d %d", &A, &B);
	C = A + B;
	numArray(C,num);
	if(C < 0){
		printf("-");
	} 
	for(int i = index -1; i >= 0; --i){
		if(num[i] == -1){
			if(i != index -1){
			printf(",");
			}
		}else{
			printf("%d",num[i]);
		}
	}
	
	return 0;

}