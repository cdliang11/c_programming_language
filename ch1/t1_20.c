

// 1-20: 编写detab, 将输入中的制表符替换成适当数目的空格
// 什么是制表符终止位，参考：
// https://blog.csdn.net/m0_37697335/article/details/79481641?spm=1001.2101.3001.6650.1&depth_1-

#include <stdio.h>

#define N 8

int main() {
  int c;
  int pos = 0;
  int nb = 0;
  while ((c = getchar()) != EOF) {
    // 不是制表符就输出
    if (c != '\t') {
      putchar(c);
      pos++;
      if (c == '\n') pos = 0; // 新行，重新计算
    } else {
      // 对 N(8)进行取模，再用N减去它得到需要填充的空格
      // nb = N - pos % N
      nb = N - pos % N;
      while (nb > 0) {
        putchar(' ');
        --nb;
      }
      pos = 0; // 重新计算
    }
  }
  return 0;
}
