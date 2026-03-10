#ifndef CALC_H
#define CALC_H
#define NUMBER         '0'
#define VAR_STORE      '$'
#define LAST_PRINT_VAL 'L'

void push(double);
double pop(void);

int getop(char[]);
int getch(void);
void ungetch(int);

void printtop();
void cptop();
void swaptop();
void clearst();

#endif
