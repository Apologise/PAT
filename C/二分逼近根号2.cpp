#include<cstdio>


int main() {
	double left = 1, right = 2;
	double eps = 1e-5;
	double mid;
	while (right - left > eps) {
		 mid = (left + right) / 2;
		if (mid*mid > 2) {
			right = mid;
		}
		else if (mid*mid < 2) {
			left = mid;
		}
		
	}
	printf("%f", mid);
	return 0;
}