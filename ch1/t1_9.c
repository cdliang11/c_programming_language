
// 1.9 输入复制到输出，其中连续的空格用一个空格代替

#include <stdio.h>

int main() {
  int c;
  int pre_char;  // 上一个输入的字符
  while ((c=getchar()) != EOF) {
    if (c == ' ' && pre_char == ' ') {}
    else {
      putchar(c);
    }
    pre_char = c;
  }
  return 0;
}
