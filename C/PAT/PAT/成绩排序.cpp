#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct{
	char name[101];
	int age;
	int score;
}Student;

//自定义排序规则
bool cmp(Student A, Student B){
	int temp;
	if(A.score != B.score){
		return A.score < B.score;
	}else if((temp = strcmp(A.name,B.name)) != 0){	//如果姓名不相同
		return temp < 0;
	}else{
		return A.age < B.age;
	}
}

int main(){
	int N;
	Student stu[1000];
	while(scanf("%d",&N) != EOF){
		for(int i = 0; i < N; ++i){
			scanf("%s%d%d",stu[i].name, &stu[i].age, &stu[i].score);
		}

		sort(stu,stu+N, cmp);
		for(int i = 0; i < N; ++i){
			printf("%s %d %d\n",stu[i].name, stu[i].age, stu[i].score);
		}
	}
	return 0;
}