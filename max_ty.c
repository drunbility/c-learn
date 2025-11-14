#include <stdio.h>
#include <limits.h>

int main() {
    printf("s min char: %d\n", SCHAR_MIN);
    printf("s max char: %d\n", SCHAR_MAX);
    printf("u min char: %u\n", UCHAR_MAX);
    printf("s min int: %d\n", SHRT_MIN);
    printf("s max int: %d\n", SHRT_MAX);
    printf("u max int: %u\n", UCHAR_MAX);
    printf("version:%d", __STDC_VERSION__);

    return 0;
}