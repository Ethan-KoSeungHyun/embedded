#include <stdio.h>
#include <math.h>

double sec(double num) { 
	return ((((num - (int)num) * 60) - (int)((num - (int)num) * 60)) * 60);
	// https://mainia.tistory.com/3178
}
int main(void) {
	double LAT1 = 37.501531;
	double LAT2 = 37.501940;
	double LONG1 = 126.933596;
	double LONG2 = 126.934304;
	int distLat, distLong;
	double result;

	double Latsec1 = sec(LAT1); // 
	double Latsec2 = sec(LAT2);
	double Longsec1 = sec(LONG1);
	double Longsec2 = sec(LONG2);

	distLat = (Latsec1 - Latsec2) * 30.887; //https://blog.naver.com/jinohpark79/221170630625
	distLong = (Longsec1 - Longsec2) * 24.668;

	printf("%d\n", distLong);
	result = sqrt(pow(distLat, 2) + pow(distLong, 2));

	printf("%f", result);
	return 0;
}

//1도 88.804km 1분 1.480km long 경도 1초 24.668m lat위도 1초 30.887m
// 37.501531, 126.933596
// 37 30 05.5 / 126 56 01.0
// 
// 
// 37.501940, 126.934304
// 37 30 07.0/ 126 56 03.5