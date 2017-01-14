//#include<cstdio>
////宏定义判断是否为闰年
//#define ISYEAP(x) (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0) ? 1 : 0
//
//
//
////定义天数
//int month[13][2] = {
//	0,0,
//	31,31,
//	28,29,
//	31,31,
//	30,30,
//	31,31,
//	30,30,
//	31,31,
//	31,31,
//	30,30,
//	31,31,
//	30,30,
//	31,31,
//};
//
//struct Date{
//	int Day;
//	int Month;
//	int Year;
//	void nextDay(){
//		Day++;
//		if(Day > month[Month][ISYEAP(Month)]){
//			Month++;
//			Day = 1;
//			if(Month > 12){
//				Year++;
//				Month = 1;
//			}
//		}
//	}
//};
//
//int abs(int a, int b){
//	int x = a - b;
//	return x < 0 ? -x : x;
//}
//
//int buf[5001][13][32];
//int main(){
//	Date temp;
//	temp.Year = 0;
//	temp.Month = 0;
//	temp.Day = 1;
//	int count = 0;
//	while(temp.Year != 5001){
//		buf[temp.Year][temp.Month][temp.Day] = count;
//		temp.nextDay();
//		count++;
//	}
//	int y1,m1,d1;
//	int y2,m2,d2;
//	scanf("%4d%2d%2d", &y1,&m1,&d1);
//	scanf("%4d%2d%2d", &y2,&m2,&d2);
//	int x = abs(buf[y1][m1][d1] , buf[y2][m2][d2]) + 1;
//	printf("%d\n",x);
//	return 0;
//}

#include <stdio.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

int dayOfMonth[13][2] = {
    0, 0, 
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31
};
struct Date {
    int Day;
    int Month;
    int Year;
    void nextDay() {
        Day++;
        if(Day > dayOfMonth[Month][ISYEAP(Year)]) {
            Day = 1;
            Month++;
            if(Month > 12) {
                Month = 1;
                Year++;
            }
        }
    }
};

int buf[5001][13][32];
int Abs(int x) {
    return x < 0 ? -x : x;
}

int main()
{
    Date tmp;
    int cnt = 0;
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 0;
    while(tmp.Year != 5001) {
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        tmp.nextDay();
        cnt++;
    }
    int d1, m1, y1;
    int d2, m2, y2;
    while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        printf("%d\n", Abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1);
    }
    return 0;
}
