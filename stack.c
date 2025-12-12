#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty, can't pop %g\n");
        return 0.0;
    }
}

void printtop() {
    if (sp > 0) {
        printf("top stack: %.8g\n", val[sp - 1]);
    } else {
        printf("empty stack,nothing print");
    }
}

void cptop() {
    if (sp > 0) {
        double t1 = pop();
        push(t1);
        push(t1);
    } else {
        printf("empty stack,cannot cp");
    }
}

void swaptop() {
    if (sp > 2) {
        double t1 = pop();
        double t2 = pop();

        push(t1);
        push(t2);
    } else {
        printf("empty stack,cannot swap");
    }
}

void clearst() {
    sp = 0;
}