#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
    int i, c, next_c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
    }
    s[1] = '\0';

    i = 0;
    if (c == '-') {
        next_c = getch();
        if (!isdigit(next_c) && next_c != '.') {
            ungetch(next_c);
            return '-';
        }
        s[++i] = c = next_c;
    } else if (!isdigit(c) && c != '.') {
        return c;
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            /* code */
        }
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            /* code */
        }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}