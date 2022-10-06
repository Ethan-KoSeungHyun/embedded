#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char gps_long[11];
char gps_lat[10];
char gps_speed[6];

void checkData() {
	for (int i = 0; i < 10; i++) {
		if ('0' > gps_long[i] || gps_long[i] > '9') {
			gps_long[0] = '0';
			gps_long[1] = NULL;
			
			break;
		}
		//printf("error count%d\n", i);
	}
	for (int i = 0; i < 9; i++) {
		if ('0' > gps_lat[i] || gps_lat[i] > '9') {
			gps_lat[0] = '0';
			gps_lat[1] = NULL;
			//printf("lat error\n");
			break;
		}
	}
	for (int i = 0; i < strlen(gps_speed); i++) {
		if ('0' > gps_speed[i] || gps_speed[i] > '9') {
			gps_speed[0] = '0';
			gps_speed[1] = NULL;
			break;
		}
	}
	
	// *3.6/1000=0.0036  //  97.2km/h = 27m/s = 27,000 mm/s -> 0.1m/s = 100 mm/s
	if (strlen(gps_speed) > 1) {
		int num = atoi(gps_speed) * 0.0036;
		
		
			if (num>9){
				
			gps_speed[0]=num/10+'0';
			gps_speed[1]=num%10+'0';
			gps_speed[2]= NULL;
			}
			else {
				gps_speed[0] =num+'0';
				gps_speed[1] = NULL;
			}
	}

}
void updateData(char* buffer) {
	int len = strlen(buffer);
	char* p;
	p = buffer;
	int colon_cnt=0;
	int comma_cnt = 0;
	int got_lat = 0, got_long = 0, got_speed = 0; // 이미 데이터를 받았는데, 다음 콤마 위치가 가까워 데이터를 또 받을까봐

	printf("updateData\n");

	for (p = buffer; p < buffer + len;p++) { // : 위치 찾음
		if (*p == ':') {
			colon_cnt++;
		}
		if (colon_cnt == 2) break; // *p가 : 두번 나온 주소일 때 break
	}
	
	for (p; p < buffer + len; p++) { // ':' 두번 나온 위치부터 나오는 ','위치 찾음
		if (*p == ',') comma_cnt++;
		if (comma_cnt == 1 && *(p + 10) == ',' && got_lat == 0) { // : 찾은 지점부터 시작된 , 가 첫번째이고 10글자 뒤에가 콤마라면
			for (int i = 0; i < 9; i++) { // 9글자 가져옴
				gps_lat[i] = *(p + i+1);
				got_lat++;
			}
			
			
		}
		if (comma_cnt == 2 && *(p + 11) == ',' && got_long == 0) { // : 찾은 지점부터 시작된 , 가 두번째이고 11글자 뒤에가 콤마라면
			for (int i = 0; i < 10; i++) { // 10글자 가져옴
				gps_long[i] = *(p + i+1);
				got_long++;
			}
			
			
		}
		
		if (comma_cnt == 7 && *(p + 3) == ',' && got_speed == 0) { // : 찾은 지점부터 시작된 , 가 다섯 번째이고 3글자 뒤에가 콤마라면
			gps_speed[0] = *(p + 1);
			gps_speed[1] = *(p + 2);
			gps_speed[2] = NULL;
			got_speed++;
		}
		if (comma_cnt == 7 && *(p + 4) == ',' && got_speed == 0) { // : 찾은 지점부터 시작된 , 가 다섯 번째이고 4글자 뒤에가 콤마라면
			gps_speed[0] = *(p + 1);
			gps_speed[1] = *(p + 2);
			gps_speed[2] = *(p + 3);
			gps_speed[3] = NULL;
			got_speed++;
		}
		if (comma_cnt == 7 && *(p + 5) == ',' && got_speed == 0) { // : 찾은 지점부터 시작된 , 가 다섯 번째이고 5글자 뒤에가 콤마라면
			gps_speed[0] = *(p + 1);
			gps_speed[1] = *(p + 2);
			gps_speed[2] = *(p + 3);
			gps_speed[3] = *(p + 4);
			gps_speed[4] = NULL;
			got_speed++;
		}
		if (comma_cnt == 7 && *(p + 6) == ',' && got_speed == 0) { // : 찾은 지점부터 시작된 , 가 다섯 번째이고 6글자 뒤에가 콤마라면
			gps_speed[0] = *(p + 1);
			gps_speed[1] = *(p + 2);
			gps_speed[2] = *(p + 3);
			gps_speed[3] = *(p + 4);
			gps_speed[4] = *(p + 5);
			gps_speed[5] = NULL;
			got_speed++;
		}
		printf("%s\n", gps_speed);
		
		
	}
	checkData();
}

int main(void) {
	char Buffer[] = { "294.92,1176.76,339.36,-1.38,36.85,-0.98,-70.05,37.50,-9.0,21.90,63.30,16.20,23:36:55.000,375526026,1270735995,41342,22697,15,3,3400,30497702,155,344234250,1.974," };
	updateData(Buffer);

	printf("gps lat: %s\n", gps_lat);
	printf("gps_long: %s\n", gps_long);
	printf("gps_speed: %s\n", gps_speed);
	return 0;
}
