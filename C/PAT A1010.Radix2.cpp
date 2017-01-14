#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL unsigned long long
using namespace std;

int tag,radix,res;
LL ans,left,right;

LL get(char ch){
	if(ch >= '0' && ch <= '9'){return ch - '0';}
		return ch - 'a' + 10;
}

int main(){
	char N1[20],N2[20],temp[20];
	scanf("%s%s%d%d", &N1, &N2, &tag, &radix);
	if(tag == 2){
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	//求二分上限
	for(int i = 0; N1[i]; ++i){
		ans = ans * radix + get(N1[i]);
	}	//	上界是ans + 1

	//求二分下限
	for(int i = 0; N2[i]; ++i){
		left = max(left,get(N2[i]));
	}

	for(right = ans +1,left ++; left <= right;){
		LL mid = (left + right) >> 1;
		LL check = 0;
		//将N2转为十进制与N1的十进制比较
		for(int i = 0; N2[i]; ++i){
			check = mid * check + get(N2[i]);
		}
		if(check == ans){ res = mid; break;}
		else if(check < ans ){
			left = mid + 1;
		}else {
			right = mid - 1;
		}
	}
	res ? printf("%d\n", res) : printf("Impossible\n");
	return 0;
}

