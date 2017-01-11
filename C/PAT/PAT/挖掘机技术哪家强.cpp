#include<cstdio>

int school[100010] = {0};
int max = 0;

int main(){
	int N;
	int ID = 0;
	int score = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d%d",&ID,&score);
		school[ID] += score; 
		if(school[max] < school[ID]){
			max = ID;
		}
	}

	printf("%d %d",max,school[max]);
	return 0;
}