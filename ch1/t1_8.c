
// 1.8 编写程序，统计空格、制表符、换行符个数

#include <stdio.h>

int main() {
  int c;
  int blank = 0, tab = 0, newline = 0;
  while ((c=getchar()) != EOF) {
    if (c == ' ') blank += 1;
    else if (c == '\t') tab += 1;
    else if (c == '\n') newline += 1;
  }
  printf("空格 %d个 制表符 %d个 换行符 %d个\n",blank, tab, newline);
  return 0;
}
