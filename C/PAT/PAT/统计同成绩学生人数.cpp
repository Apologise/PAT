#include<stdio.h>

#define MaxSize 1001

int main(){
	int N;	//ѧ��������
	int stu[MaxSize] = {0},sum[MaxSize] = {0};
	int j = 0;
	while(scanf("%d",&N) != EOF){
		if(N == 0){
			for(int i = 0; i < j; i++){
				printf("%d\n", sum[i]);
			}
			break;
		}
		//����ÿһλѧ���ĳɼ�
		for(int i = 0; i < N; ++i){
			scanf("%d", &stu[i]);
		}
		//����ָ���ķ���
		int score;
		scanf("%d",&score);
		for(int i = 0; i < N; ++i){
			if(score == stu[i]){ sum[j]++;}
		}
		j++;
	}
}