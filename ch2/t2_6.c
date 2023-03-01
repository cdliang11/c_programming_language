
// 2.6 编写一个函数 setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：
// 将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，x的其余各位保持不变。

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
  int a, b, c, d;
  printf("Please enter original number: ");
  scanf("%d", &a);
  printf("Please enter bits: ");
  scanf("%d", &b);
  printf("Please enter move number: ");
  scanf("%d", &c);
  printf("Please enter compare number: ");
  scanf("%d", &d);
  printf("Result=%d\n", setbits(a, b, c, d));
  return 0;
}

int setbits(int x, int p, int n, int y) {
  return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
}
