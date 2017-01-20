#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define maxn 40010
using namespace std;

//存放 学生姓名编号
vector<int> stuName[2510];
char name[maxn][5];

//这个比较比较比较巧妙 
bool cmp(int a, int b){
	return strcmp(name[a],name[b]) < 0;
}
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i = 0; i < N; i++){
		int x;	//	该学生选的课程的总数 
		scanf("%s %d",name[i], &x);
		for(int j = 0; j < x; ++j){
			int course;
			scanf("%d",&course);
			stuName[course].push_back(i);
		}
	}
	
	for(int i = 1; i <= K; ++i){
		printf("%d %d\n",i,stuName[i].size());
		sort(stuName[i].begin(),stuName[i].end(),cmp);
		for(int j = 0; j < stuName[i].size(); ++j){
			printf("%s\n",name[stuName[i][j]]);
		}
	}
	return 0;
}
 
