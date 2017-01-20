#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 26*26*26*10+1
using namespace std;


vector<int> selectCourse[maxn];

int getID(char str[]){
	int id = 0;
	for(int i = 0; i < 3; i++){
		id = id*26 + str[i] - 'A';
	}
	id += str[3] - '0';
	return id;
}

int main(){
	char name[5];
	int N,K;
	scanf("%d%d",&N, &K);
	for(int i = 0; i < K; ++i){
		int course,x;	//	course代表课程编号，x代表选该课程的学生人数 
		scanf("%d %d",&course,&x);
		for(int j = 0; j < x; j++){
			scanf("%s",name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}
	
	//查询学生的名单
	for(int i = 0; i < N; ++i) {
		scanf("%s",name);
		int id = getID(name);
		int size = selectCourse[id].size();
		sort(selectCourse[id].begin(), selectCourse[id].end());
		scanf("%s %d",name, size);
		for(int i = 0; i < size; ++i){
			printf(" %d",selectCourse[id][i]);
		}
		printf("\n");;
	}
	return 0;
}