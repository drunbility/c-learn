#include <stdio.h>

int strindex(char s[], char t[]) {
    int i, j, k;

    // for (i = 0; i < s[i] != '\0'; i++) {
    //     for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
    //     }
    //     if (k > 0 && t[k] == '\0') {
    //         return i;
    //     }
    // }

    // return -1;

    int result = -1;

    for (i = 0; i < s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
        }
        if (k > 0 && t[k] == '\0') {
            result = i;
            continue;
        }
    }

    return result;
}

int main() {
    char s[] = "1343dgsadggdq";
    char t[] = "dg";

    printf("index: %d", strindex(s, t));
}