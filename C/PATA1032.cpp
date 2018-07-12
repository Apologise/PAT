#include<stdio.h>
#include<string.h>
const int maxn = 100001;
int main(){
	int n;
	scanf("%d", &n);
	int score[maxn];
	memset(score, 0, sizeof(score));
	for(int i = 0; i < n; ++i){
		int id,_score;
		scanf("%d %d",&id,&_score);
		score[id] += _score;
	}
	int maxId = 0, maxScore = 0;
	for(int i = 1; i <= n; ++i){

		if(score[i] > maxScore){
			maxScore = score[i];
			maxId = i;
		}
	}
	printf("%d %d", maxId, maxScore);
	return 0;
}