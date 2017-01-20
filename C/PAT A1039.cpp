#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 26*26*26*10+1
using namespace std;

struct Student{
	int course[2510];
	int count;
	char name[5];
	Student(){
		count = 0;
	}
	
};
int getID(char str[]){
	int id = 0;
	for(int i = 0; i < 3; i++){
		id = id * 26 + str[i] - 'A';
	}	
	id = str[3] - '0';
	return id;
}
Student stu[40000];

int main(){
	char name[5];
	int n ,k;
	scanf("%d%d",&n, &k);
	for(int i = 0; i < k; i++){
		int course,x;	//	course代表课程序号，x代表选course的人数
		scanf("%d%d", &course, &x);
		for(int j = 0; j < x; j++){
			scanf("%s",name);
			int id = getID(name);
			strcpy(stu[id].name, name);
			stu[id].course[stu[id].count++] = course;
		} 
	}
	//查询名单 
	for(int i = 0; i < n; ++i){
		scanf("%s",name);
		int id = getID(name);
		sort(stu[id].course, stu[id].course + stu[id].count);
		printf("%s %d",stu[id].name, stu[id].count);
		for(int j = 0; j < stu[id].count; j++){
			printf(" %d",stu[id].course[j]);
		}
		printf("\n");
	}
	return 0;
}
