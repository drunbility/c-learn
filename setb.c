#include <stdio.h>

unsigned getbs(unsigned x, int p, int n);

unsigned setbs(unsigned x, int p, int n, unsigned y);

unsigned getbs(unsigned x, int p, int n) {
    return (x >> (p - n + 1)) & (~((~0) << n));
}

unsigned setbs(unsigned x, int p, int n, unsigned y) {
    unsigned x_c = x & ~((~(~0 << n)) << (p + 1 - n));
    unsigned y_c = (y & ~(~0 << n)) << (p + 1 - n);

    return x_c | y_c;
}

void print_binary(unsigned char n) {
    // 从最高位开始检查
    for (int i = 7; i >= 0; i--) {
        // 使用右移和按位与来检查每一位
        putchar((n >> i) & 1 ? '1' : '0');
    }
}

int main() {
    unsigned char x = 171;
    unsigned char y = 202;
    int p = 6;
    int n = 4;

    printf("origin x: %3d\n", x);
    print_binary(x);
    printf("\norigin y: %3d\n", y);
    print_binary(y);

    unsigned res = setbs(x, p, n, y);

    printf("\nresult: %3d\n", res);
    print_binary(res);

    return 0;
}