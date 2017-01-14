/*
Author:Apolo
Time : 2017-01-14 
Problem Description：判断一个序列主元的个数并输出 
Method；类似于数PAT的个数                                                                                       
*/ 
#include<cstdio>
#include<algorithm>
#define maxn 100010
#define INF 1<<31-1 //INT_MAX 
using namespace std;

int num[maxn] = {0};
int N;

int leftMax[maxn] = {0}, rightMin[maxn];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}
	

	//从左遍历，计算leftMax 
	for(int i = 1; i < N; ++i){
		if(num[i - 1] > leftMax[i - 1]){
			leftMax[i] = num[i -1];				
		}else{
			leftMax[i] = leftMax[i - 1];
		}
	}
	
	//从右往左遍历，计算rightMin
	rightMin[N-1] = INF;
	for(int i = N-2; i >= 0; i--){
		if(num[i + 1] < rightMin[i + 1] ){
			rightMin[i] = num[i + 1];
		}else{
			rightMin[i] = rightMin[i + 1];
		}
	}

	
	int count[maxn],index = 0;
	for(int i = 0; i < N; ++i){
		if(num[i] > leftMax[i] && num[i] < rightMin[i]){
			count[index++] = num[i];
		}
	}
	printf("%d\n",index);
	for(int i = 0; i < index; i++){
		printf("%d", count[i]);
		if(i < index - 1){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
 