#include<cstdio>
#include<algorithm>
using namespace std;
//��˼��ϸ��̫��Ҫ�ˣ�ʹ��sort����sort(coins+1,coins N +1);ע����N+1����N����Ϊ��ǰ�պ�
int coins[100010] = {0};
int N, M;

//two pointer����
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
//ʹ��two point�������ֽ�������С��������
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
////ʹ��two point�������ֽ�������С��������
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