#include<cstdio>
//宏定义判断是否为闰年
#define ISYEAP(x) (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0) ? 1 : 0



//定义天数
int month[13][2] = {
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
};

struct Date{
	int Day;
	int Month;
	int Year;
	void nextDay(){
		Day++;
		if(Day > month[Month][ISYEAP(Month)]){
			Month++;
			Day = 1;
			if(Month > 12){
				Year++;
				Month = 1;
			}
		}
	}
};

int abs(int a, int b){
	int x = a - b;
	return x < 0 ? -x : x;
}

int buf[5001][13][32];
int main(){
	Date temp;
	temp.Year = 0;
	temp.Month = 0;
	temp.Day = 1;
	int count = 0;
	while(temp.Year != 5001){
		buf[temp.Year][temp.Month][temp.Day] = count;
		temp.nextDay();
		count++;
	}
	int y1,m1,d1;
	int y2,m2,d2;
	scanf("%4d%2d%2d", &y1,&m1,&d1);
	scanf("%4d%2d%2d", &y2,&m2,&d2);
	int x = abs(buf[y1][m1][d1] , buf[y2][m2][d2]) + 1;
	printf("%d\n",x);
	return 0;
}