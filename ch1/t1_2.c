
#include <stdio.h>

int main() {
  // 如果不是规定的转义字符
  // 程序在编译的时候会报警告
  // warning: unknown escape sequence: '\c'
  // 输出的结果是: aacbb
  printf("aa\cbb\n");
  return 0;
}