
// 2.9 在求对2的补码时，表达式x &= (x - 1)可以删除x中最右边值为1的一个二进制位。
// 请解释这样做的道理。用这一方法重写bitcount函数，以加快其执行速度。

// ans: 任何整数的二进制都可以表示为xx…x10…0的形式
// 减1后等于xx…x01…1，二者按位与得到xx…x00…0，即相当于将最右边一个1置为0。

#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned a;
  int i;
  printf("输入一个十六进制数: ");
  scanf("%x", &a);
  printf("值为1的位数:%d\n", bitcount(a));
  return 0;
}

int bitcount(unsigned x) {
  int b = 0;
  while (x != 0) {
    x &= (x - 1);
    b++;
  }
  return b;
}
