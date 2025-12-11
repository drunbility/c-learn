#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[]) {
    int i, j = 0;
    int start, end;

    while (s1[i] != '\0') {
        if (s1[i + 1] == '-' && s1[i + 2] != '\0') {
            start = s1[i];
            end = s1[i + 2];
            if ((islower(start) && islower(end) && start < end) || (isupper(start) && isupper(end) && start < end) ||
                (isdigit(start) && isdigit(end) && start < end)) {
                char c;
                for (c = start; c <= end; c++) {
                    s2[j++] = c;
                }
                i += 3;
            } else {
                s2[j++] = s1[i++];
            }
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}

void run_test(const char* testchar) {
    char result[100];
    expand(testchar, result);
    printf("ori: \"%s\"\n", testchar);
    printf("result: \"%s\"\n", result);
}

int main() {
    run_test("a-z");

    run_test("a-b-c");

    run_test("z-a");

    run_test("Test: 0-3 and a-c and X-Z end-");

    return 0;
}