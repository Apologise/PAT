#include<cstdio>

int partition(int A[], int left, int right){
	int temp = A[left];

	while(left < right){
		while(A[right] > temp && right > left){
			right--;
		}
		A[left] = A[right];
		while(A[left] < temp && right > left){
			left ++;
		}
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void quickSort(int A[], int left, int right){
	if(left < right){
		int pos = partition(A,left,right);
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
	}
}

int main(){
	int A[10] = {9,1,2,5,4,3,0,7,6,8};
	quickSort(A, 0, 9);
	for(int i = 0; i < 10; ++i){
		printf("%d ", A[i]);
	}
	return 0;
}