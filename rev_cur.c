#include <stdio.h>
#include <string.h>

void rev_cur(char s[], int i, int j) {
    if (i >= j)
        return;
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    rev_cur(s, i + 1, j - 1);
}

int main() {
    char s[] = "abcd";
    int n = strlen(s);
    rev_cur(s, 0, n - 1);
    printf("%s", s);
    int x = 1, y = 2;
    int *p;
    p = &x;
    y = *p;
    *p = 0;

    return 0;
}