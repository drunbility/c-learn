#include <stdio.h>
#include <ctype.h>

int mhtoi(char[]);
int mhtoi(char s[]) {
    int i = 0, n = 0;
    int hext;
    if (s[i] == '0' || s[i] == 'x' || s[i] == 'X') {
        i++;
    }

    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            hext = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hext = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hext = s[i] - 'A' + 10;
        } else {
            break;
        }

        n = n * 16 + hext;
        i++;
    }

    return n;
}

int main() {
    printf("htoi(\"F\")       = %d (Expected: 15)\n", mhtoi("F"));
    printf("htoi(\"0xG\")       = %d (Expected: 0)\n", mhtoi("0xG"));
    return 0;
}
