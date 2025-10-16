#include <stdio.h>
float main() {
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    /* 温度表的下限 */
    upper = 300;
    /* 温度表的上限 */
    step = 20;
    /* 步长 */
    celsius = lower;
    printf("%3s %6s\n", "摄氏温度", "华氏温度");
    while (fahr <= upper) {
        fahr = (9.0 / 5.0) * (celsius + 32.0);
        // printf("%d",celsius);
        printf("%8.0f %8.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}