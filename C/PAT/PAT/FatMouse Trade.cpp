#include<stdio.h>
#include<algorithm>
using namespace std;

struct goods{
	double j;	//总重
	double f;	//总价值
	double s;	//性价比
}buf[1000];

bool cmp(goods A, goods B){
	return A.s > B.s;
}

int main(){
	double m;
	int n;
	while(scanf("%lf%d",&m,&n) != EOF){
		if(m == -1 && n == -1){break;}
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf", &buf[i].j,&buf[i].f);
			buf[i].s = buf[i].j / buf[i].f;
		}
		sort(buf, buf+n, cmp);
		int index = 0;
		double ans = 0;
		while(m > 0 && index < n){
			if(m > buf[index].j){
				ans += buf[index].j;
				m -= buf[index].j;
			}else{
				ans += buf[index].j * m/buf[index].f;
				m = 0;
			}
			index ++;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}