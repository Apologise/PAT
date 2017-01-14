#include<stdio.h>
#include<algorithm>
#include<string>

using namespace std;

typedef struct{
	char no[100];
	char name[20];
	char sex[10];
	int age;
}Student;


//使用二分查找必须先要将其变为有序的数列
//先定义排序规则。由小到大
bool cmp(Student A, Student B){
	return strcmp(A.no,B.no) < 0;
}

Student buf[1001];

int main{
	int n;

}