#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct{
	char registration_num[15];
	int final_rank;
	int location_number;
	int local_rank;
	int score;
}Student;

Student stu[30010];

bool cmp(Student A, Student B){
	if(A.score != B.score){
		return A.score > B.score;
	}else {
		return strcmp(A.registration_num, B.registration_num) < 0;
	}
}

int main(){
	int N, test_num[310];	//N代表考场数，test_num代表每个考场的人数
	scanf("%d",&N);
	int sumStu = 0,sum = 0;
	for(int i = 0; i < N; ++i){
		scanf("%d",&test_num[i]);
		for(int j = 0; j < test_num[i]; ++j){
			scanf("%s%d",&stu[j + sumStu].registration_num,&stu[j+sumStu].score);
			stu[j + sumStu].location_number = i+1;
		}
		//计算考场排名
		sort(stu+sumStu,stu + sumStu+test_num[i],cmp);
		stu[sumStu + 0].local_rank = 1;
		for(int k = 1; k < test_num[i]; ++k){
			if(stu[sumStu+k].score == stu[sumStu + k -1].score){
				stu[sumStu+k].local_rank = stu[sumStu+k -1].local_rank;
			}else {
				stu[sumStu+k].local_rank = k + 1;
			}
		}
		sumStu += test_num[i];

	}
	sort(stu,stu+sumStu,cmp);
	stu[0].final_rank = 1;
	for(int i = 1; i < sumStu; ++i){
		if(stu[i].score == stu[i - 1].score){
			stu[i].final_rank = stu[i - 1].final_rank;
		}else{
			stu[i].final_rank = i + 1;
		}
	}
	printf("%d\n",sumStu);
	for(int i = 0; i < sumStu-1; i++){
		printf("%s %d %d %d\n",stu[i].registration_num,stu[i].final_rank,stu[i].location_number,stu[i].local_rank);
	}
	printf("%s %d %d %d",stu[sumStu-1].registration_num,stu[sumStu-1].final_rank,stu[sumStu-1].location_number,stu[sumStu-1].local_rank);
	return 0;
}

