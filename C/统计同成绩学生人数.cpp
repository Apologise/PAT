#include<stdio.h>

#define MaxSize 1001

int main(){
	int N;	//学生的人数
	int stu[MaxSize] = {0},sum[MaxSize] = {0};
	int j = 0;
	while(scanf("%d",&N) != EOF){
		if(N == 0){
			for(int i = 0; i < j; i++){
				printf("%d\n", sum[i]);
			}
			break;
		}
		//输入每一位学生的成绩
		for(int i = 0; i < N; ++i){
			scanf("%d", &stu[i]);
		}
		//输入指定的分数
		int score;
		scanf("%d",&score);
		for(int i = 0; i < N; ++i){
			if(score == stu[i]){ sum[j]++;}
		}
		j++;
	}
}