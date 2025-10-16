#include <stdio.h>
/* count characters in input; 1st version */
int main() {
    int c, ns, nt, nl;
    ns, nt, nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n') {
            ++nl;
        } else if (c == ' ') {
            ++ns;
        } else if (c == '\t') {
            ++nt;
        }
    printf("%ld ,%ld ,%ld ,", ns, nt, nl);
}
