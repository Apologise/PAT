#include<cstdio>
#include<algorithm>
using namespace std;
//反思：细心太重要了，使用sort函数sort(coins+1,coins N +1);注意是N+1不是N，因为是前闭后开
int coins[100010] = {0};
int N, M;

//two pointer方法
int func(int A[], int left, int right){
	int min = 1010;
	while(left < right){
		if(A[left] + A[right] == M){
			if(A[left] < min){
				min = A[left];
				//break;
			}
			left++;
			right--;
		}else if(A[left] + A[right] < M){
			left++;
		}else {
			right--;
		}
	}
	return min;
}
//使用two point方法，现将序列有小到大排序
int main(){
	scanf("%d%d", &N,&M);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &coins[i]);
	}
	sort(coins+1,coins + N+1);
	int ans = func(coins,1,N);
	if(ans == 1010){
		printf("No Solution");
	}else{
		printf("%d %d\n", ans,M-ans);
	}
}

//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//int coins[100010] = {0};
//
//int N, M;
//
//int func(int A[], int left, int right){
//  int min = 1010;
//  while(left < right){
//    if(A[left] + A[right] == M){
//      if(A[left] < min){
//        min = A[left];
//        break;
//      }
//      left++;
//      right--;
//    }else if(A[left] + A[right] < M){
//      left++;
//    }else {
//      right--;
//    }
//  }
//  return min;
//}
////使用two point方法，现将序列有小到大排序
//int main(){
//  
//  scanf("%d%d", &N,&M);
//  for(int i = 1; i <= N; ++i){
//    scanf("%d", &coins[i]);
//  }
//  sort(coins+1,coins +N+1);
//  int ans = func(coins,1,N);
//  if(ans == 1010){
//    printf("No Solution");
//  }else{
//    printf("%d %d\n", ans,M-ans);
//  }
//}