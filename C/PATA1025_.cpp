#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


struct Student{
	char id[20];
	int score;
	int localid;
	int finalid;
	int localRank;
}stu[30001];

bool cmp(Student a, Student b){
	if(a.score != b.score){
		return a.score > b.score;
	}else{
		return strcmp(a.id, b.id) < 0;
	}
}
int main(){
	int N, num = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			scanf("%s %d", stu[num].id,&stu[num].score );
			stu[num].localid = i;
			num++;
		}
		sort(stu+num - n, stu+num, cmp);
		int r = 1;
		for(int k = num - n; k < num; ++k){
			if(k == num - n){
				stu[k].localRank = r;
			}else if(stu[k].score != stu[k-1].score){
				stu[k].localRank = k - num+n + 1;
			}else{
				stu[k].localRank = stu[k-1].localRank;
			}
		}
	}
	sort(stu, stu+num, cmp);
	for(int i = 0; i < num; ++i){
		if(i == 0){
			stu[i].finalid = 1;
		}else{
			if(stu[i].score != stu[i-1].score){
				stu[i].finalid = i+1;
			}else{
				stu[i].finalid = stu[i-1].finalid;
			}
		}
	}
	printf("%d\n", num);
	for(int i = 0; i < num; ++i){
		if(i == num -1)
			printf("%s %d %d %d", stu[i].id, stu[i].finalid, stu[i].localid, stu[i].localRank);
		else
			printf("%s %d %d %d\n", stu[i].id, stu[i].finalid, stu[i].localid, stu[i].localRank);
	}
}
