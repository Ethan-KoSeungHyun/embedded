#include <stdio.h>

float vol;
float vol_per;

float Cal_percent(float vol);


int main() {
    float input = 1023.0; // input ADC
    float voltage = (input/1023)*3.3; // ADC to Voltage
    printf("Input Voltage: %fV\n",voltage);
    vol = voltage/0.881198; // calculate max 3.3 to 3.7
    printf("Voltage Sensor(before register): %fV\n",vol);
    vol = vol/0.06369; // calculate battery voltage
    vol_per = Cal_percent(vol);

    printf("Battery Voltage: %fV\nBattery Percent: %f%%",vol,vol_per);
    return 0;
}

float Cal_percent(float vol){
    if(vol>=57.4){
        return (float)(1.428*vol)+16;
    } else if(vol>=51.9) {
        return (float)6.91 * vol - 298.58;
    } else if(vol>=51.24){
        return (float)500/33*vol-7990/11;
    } else if(vol>=49){
        return (float)125/7*vol-865;
    } else if(vol>=46.2){
        return (float)5/14*vol-15/2;
    } else{
        return (float)45/14*vol-279/2;
    }
}
