
// 编写程序entab, 将空格串替换为最少数量的制表符和空格
// 保持单词之间的间隔不变


#include <stdio.h>

#define N 8

int main() {
  int i, j, c, lastc;
  lastc = 'a'; // 字符
  i = j = 0;
  while ((c = getchar()) != EOF) {
    if (lastc == ' ' && c == ' ') i++;
    else if (c == ' ') {
      lastc = ' ';
      i = 1;
    } else {
      for (j = 0; j < i / N; j++) {
        putchar('\t');
      }
      for (j = 0; j < i % N; j++) {
        putchar(' ');
      }
      i = 0;
      lastc == 'a';
      putchar(c);
    }
  }
  if (lastc == ' ') {
    for (j = 0; j < i / N; j++)
      putchar('\t');
    for (j = 0; j < i % N; j++)
      putchar(' ');
  }
  return 0;
}
