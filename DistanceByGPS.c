#include <stdio.h>
#include <math.h>

double sec(double num) { 
	return ((((num - (int)num) * 60) - (int)((num - (int)num) * 60)) * 60); // degree -> sec
	// https://mainia.tistory.com/3178
}
int main(void) {
	double LAT1 = 37.501531;
	double LAT2 = 37.501940;
	double LONG1 = 126.933596;
	double LONG2 = 126.934304;
	int distLat, distLong;
	double result;

	double Latsec1 = sec(LAT1); 
	double Latsec2 = sec(LAT2);
	double Longsec1 = sec(LONG1);
	double Longsec2 = sec(LONG2);

	distLat = (Latsec1 - Latsec2) * 30.887; //https://blog.naver.com/jinohpark79/221170630625
	distLong = (Longsec1 - Longsec2) * 24.668; // 24.668 m/sec

	result = sqrt(pow(distLat, 2) + pow(distLong, 2));

	printf("%f", result);
	return 0;
}

// long 1sec: 24.668m lat 1sec : 30.887m (at south korea (LAT ~= 37))
// 37.501531, 126.933596
// 37 30 05.5 / 126 56 01.0
// 
// 
// 37.501940, 126.934304
// 37 30 07.0/ 126 56 03.5
