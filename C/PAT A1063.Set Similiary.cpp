/*
Author:Apolo
Time : 2017-01-14
Problem Description：
Method；
*/
#include<cstdio>
#include<set>
using namespace std;

set<int> st[51];

void isEqual(int x,int y){	//	比较st[x]与st[y]集合
 	int totalNum = st[y].size(), sameNum = 0;
	 for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++){
	 	if(st[y].find(*it) != st[y].end()){
		 	sameNum ++;
		 } else{
			totalNum ++; 
	 	}
	 } 
	 printf("%.1lf%\n",sameNum * 100.0/totalNum);
 } 
 
 int main(){
 	int N;
 	scanf("%d", &N);
 	for(int i = 1; i <= N; ++i){
	 	int count,x;
	 	scanf("%d",&count);
	 	for(int j = 0; j < count; ++j){
		 	scanf("%d",&x);
		 	st[i].insert(x);
		 }
	 }
	 //要查询的集合 
	 int K;
	 scanf("%d", &K);
	 for(int i = 0;i < K; ++i){
	 	int x, y;
	 	scanf("%d %d", &x, &y);
	 	isEqual(x,7);
	 } 
	 return 0;
 }