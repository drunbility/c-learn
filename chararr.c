#include <stdio.h>

#define MAXLINE_LEN 1000

int read_line(char line[]);
void copy(char to[], char from[]);
int rt_blank(char line[]);
void rv_line(char line[]);
int main() {
    int len;
    int max = 0;

    char line[MAXLINE_LEN];
    char longest[MAXLINE_LEN];

    while ((len = read_line(line)) > 0) {
        int new_len = rt_blank(line);

        if (new_len > max) {
            max = new_len;
            // rv_line(line);
            copy(longest, line);
        }
    }

    if (max > 1) {
        rv_line(longest);
        printf("%s", longest);
    }

    return 0;
}

void rv_line(char line[]) {
    char tmp_line[MAXLINE_LEN];
    copy(tmp_line, line);
    int i = 0;
    while (line[i] != '\n') {
        i++;
    }
    for (int j = 0; j < i; j++) {
        line[j] = tmp_line[i - 1 - j];
    }
}

int read_line(char line[]) {
    int c;
    int i = 0;

    while ((i < MAXLINE_LEN - 1) && (c = getchar()) != EOF && (c != '\n')) {
        line[i] = c;
        i++;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

int rt_blank(char line[]) {
    int i = 0;
    while (line[i] != '\0') {
        i++;
    }

    while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
        i--;
    }

    if (i >= 0) {
        i++;
        line[i] = '\n';
        i++;
        line[i] = '\0';
    } else {
        line[0] = '\0';
    }

    return i;
}