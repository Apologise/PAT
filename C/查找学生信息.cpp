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


//ʹ�ö��ֲ��ұ�����Ҫ�����Ϊ���������
//�ȶ������������С����
bool cmp(Student A, Student B){
	return strcmp(A.no,B.no) < 0;
}

Student buf[1001];

int main{
	int n;

}