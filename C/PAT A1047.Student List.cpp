#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 40010;
const int N = 40010; 
vector<int> Course[2510];
char name[maxn][5];

bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
}

int main(){
	int n,k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		int course;
		scanf("%s %d",name[i], &course);
		for(int j = 0; j < course; j++){
			int courseID;
			scanf("%d", &courseID);
			Course[courseID].push_back(i);
		}
	}
	
	for(int i = 1; i <= k; i++){
		printf("%d %d\n",i,Course[i].size());
		sort(Course[i].begin(), Course[i].end(),cmp);
		for(int j = 0; j < Course[i].size(); j++){
			printf("%s\n",name[Course[i][j]]);
		}
	}
	return 0;
}