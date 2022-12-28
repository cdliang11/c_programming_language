
// 1.10 输入复制到输出，将制表符替换为\t
// 回退符替换为\b 反斜杠替换为\\

#include <stdio.h>

int main() {
  int c;
  int pre_char;  // 上一个输入的字符
  while ((c=getchar()) != EOF) {
    if (c == '\t') printf("\\t");
    else if (c == '\b') printf("\\b");
    else if (c == '\\') printf("\\");
    else putchar(c);
  }
  return 0;
}
