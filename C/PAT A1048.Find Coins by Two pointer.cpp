/*
Author:Apolo
Time : 2017-01-13
Problem Description��Find Coins
Method��Two pointers
*/
#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;

int num[maxn];
int N,M;
int twoPointers(int num[], int left, int right){
	int i = left, j = right;
	while(i < j){
		if(num[i] + num[j] == M){
			break;
		}else if(num[i] + num[j] < M){
			i++;
		}else{
			j--;
		}
	}
	if(i < j){
		printf("%d %d\n", num[i], num[j]);
	}else{
		printf("No Solution\n");
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	sort(num, num+N);
	twoPointers(num,0, N-1);
	return 0;
}