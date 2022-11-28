
#include <stdio.h>
#include <ctype.h>

#define MAXOP 100  // 最大操作符长度
#define NUMBER  '0'
#define MAXVAL 100  // val栈的最大深度

int sp = 0;  // 下一个空闲栈的位置
double val[MAXVAL];

void push(double);  // 压入栈
int getop(char []);  // 得到运算符
double pop(void);

main() {
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknow command %s\n", s);
        break;
    }
  }
  return 0;
}

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error, stack empty\n");
    return 0.0;
  }
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  // 把字符压回到输入中
  if (bufp >= BUFFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t');
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c;   // 不是数字
  }
  i = 0;
  if (isdigit(c)) {
    // 收集整数部分
    while (isdigit(s[++i] = c = getch()));
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()));
  }
  s[i] = '\0';
  // 压回超前读入的一个字符
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}
