
// 2.10 重新编写大写转小写的程序
// 使用条件表达式替代 if-else

#include <stdio.h>

int lower(char x);

int main() {
  char c, b;
  while ((c = getchar()) != EOF) {
    b = lower(c);
    printf("%c", b);
  }
  return 0;
}

int lower(char x) {
  x = (x >= 'A' && x <= 'Z') ? (x - 'A' + 'a') : x;
  return x;
}
