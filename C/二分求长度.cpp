#include<cstdio>
int segments(int a[], int n, int length) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += a[i] / length;
	}
	return cnt;
}
int main() {
	int a[3] = {10, 24, 15};
	int N = 3;
	int K = 6;
	int left = 1, right = 24;
	int mid, flag = 1;
	while (left < right) {
		 mid = (left + right)/2;
		 int x = segments(a, 3, mid);
		if (x >= K) {
			left = mid;
			flag = 0;
		}
		else if (x < K) {
			if (flag == 0) {
				break;
			}
			else {
				right = mid;
			}
		}
	}
	printf("%d", left);
	return 0;
}