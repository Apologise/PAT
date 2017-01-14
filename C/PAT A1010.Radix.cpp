#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL long long



LL Map[256];
LL inf = (1LL << 63) - 1;

void init(){
	for(char c = '0'; c <= '9'; c++){
		Map[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++){
		Map[c] = c - 'a' + 10;
	}
}

LL convertNum10(char A[], LL radix,LL t){
	int len = strlen(A);
	LL ans = 0;
	for(int i = 0; i < len; ++i){
		ans = radix * ans + Map[A[i]];
		if(ans < 0 || ans > t){return -1;}
	}
	return ans;
}

//下界
int findLargeN2(char A[]){
	int len = strlen(A);
	int max = -1;
	for(int i = 0; i < len; ++i){
		if(Map[A[i]] > max){
			max = Map[A[i]];
		}
	}
	return max + 1;
}



int cmp(char N2[], LL radix, LL t){
	int len = strlen(N2);
	LL num = convertNum10(N2,radix,t);
	if(num < 0){return 1;}
	if(t > num){
		return -1;
	}else if(t == num){
		return 0;
	}else{
		return 1;
	}
}

//二分比较求出进制
LL binarySearch(char N2[], LL left, LL right, LL t){
	LL mid;
	while(left <= right){
		mid = (left + right) / 2;
		int flag  = cmp(N2, mid, t);
		if(flag == 0){	return mid;}
		else if(flag == -1){
				left = mid + 1;
		}else {
			right = mid - 1;
		}
	}
	return -1;
}

char N1[20], N2[20], temp[20];
int tag,radix;

int main(){
	init();
	//1，将已经确定的进制数放在N1，未确定的放在N2
	scanf("%s %s %d %d", &N1, &N2, &tag, &radix);
	if(tag == 2){
		strcpy(temp, N2);
		strcpy(N2, N1);
		strcpy(N1, temp);
	}

	//将N1转换为十进制
	LL t = convertNum10(N1, radix,inf);
	LL low = findLargeN2(N2);
	LL high = max(low,t) + 1;
	LL ans = binarySearch(N2, low, high,t);
	if(ans == -1)printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
} 