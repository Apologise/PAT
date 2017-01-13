#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 110
//先分别写出归并排序和插入排序

//1、归并排序,递归实现
int k = 0;
void merge(int num[], int L1, int R1, int L2, int R2){
	int temp[maxn];
	int i = L1, j = L2,index = 0;
	while(i <= R1 && j <= R2){
		if(num[i] < num[j]){
			temp[index++] = num[i++];
		}else{
			temp[index++] = num[j++];
		}
	}
	while(i <= R1){
		temp[index++] = num[i++];
	}
	while(j <= R2){
		temp[index++] = num[j++];
	}
	for(int i = 0; i < index; i++){
		num[L1 + i] = temp[i];
	}
	
}
//
//void mergeSort(int num[], int left, int right){
//	if(left < right){
//		int mid = (left + right)/ 2;
//		mergeSort(num, left, mid);
//		mergeSort(num, mid + 1, right);
//		merge(num, left, mid, mid + 1, right);
//	}
//}
//
////2.非递归实现
//
//void mergeSort2(int A[]){
//	for(int step = 2; step/2 < 10; step *= 2){
//		for(int i = 0; i< 10; i += step){
//			sort(A+i,A+min(i + step,10));
//		}
//	}
//}
//
////Test
//int main(){
//	int count = 0;
//	int num[10] = {9,8,0,7,5,6,3,4,1,2};
//	mergeSort2(num);
//	for(int i = 0; i < 10; ++i){
//		printf("%d ", num[i]);
//	}
//	
//	return 0;
//}

#include<cstdio>
#include<algorithm>
using namespace std;
#define  N  111
int origin[N], tempOri[N], changed[N];
int n;
bool isSame(int A[], int B[]){
	for(int i = 0; i < n; ++i){
		if(A[i] != B[i]){
			return false;
		}
	}
	return true;
}

void  showArray(int A[]){
	for(int i = 0; i < n; ++i){
		printf("%d", A[i]);
		if(i < n - 1){
			printf(" ");
		}
	}
	printf("\n");
}

bool insertSort(){
	bool flag = false;
	for(int i = 1; i < N; ++i){
		if(i != 1 && isSame(tempOri, changed)){
			flag = true;
		}
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j - 1] > temp){
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true){
			return true;
		}
	}
	return false;
}

void mergeSort(){
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && isSame(tempOri,changed)){
			flag = true;
		}
		for(int i = 0; i < n; i+= step){
			sort(tempOri + i, tempOri + min(i + step, n));
		}
		if(flag == true){
			showArray(tempOri);
			return ;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &changed[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	}else{
			printf("Merge Sort\n");
			for(int i = 0; i < n; ++i){
				tempOri[i] = origin[i];
			}
			mergeSort();
	}
	return 0;
}