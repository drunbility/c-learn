#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float main() {
    // float fahr,celsius;
    // float lower, upper, step; 
    // lower = 0;      
    // /* 温度表的下限 */ 
    // upper = 300;    
    // /* 温度表的上限 */ 
    // step = 20;      
    // /* 步长 */ 
    // fahr = lower; 
    // printf("%3s %6s\n","华氏温度","摄氏温度");
    // while (fahr <= upper) { 
    //     celsius = (5.0/9.0) * (fahr-32.0); 
    //     // printf("%d",celsius);
    //     printf("%8.0f %8.1f\n", fahr, celsius); 
    //     fahr = fahr + step; 
    // } 

    int fahr;
    for (fahr = UPPER; fahr >= LOWER; fahr= fahr-STEP)
        printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
         
}  