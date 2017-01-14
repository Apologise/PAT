//思路：先从左至右遍历存放P的个数，然后从右至左计算T的个数
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	char str[100010];
	int P[100010] = {0};

	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i){
		if(i > 0){
			P[i] = P[i - 1];
		}
		if(str[i] == 'P'){
			P[i]++;
		}
	}

	int ans = 0,rightT = 0;
	for(int i = len -1; i >= 0; --i){
		if(str[i] == 'T'){
			rightT++;
		}else if(str[i] == 'A'){
			ans += P[i]*rightT;
		}
	}
	printf("%d\n",ans);
	return 0;
}