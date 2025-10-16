#include <stdio.h>

int main() {
    int c;
    printf("EOF 的值是：%d\n", EOF);
    while ((c=getchar())==EOF)
    {
        putchar(c);
    }
    

}