
// 2.8 rightrot(x, n) 循环右移n位

#include <stdio.h>

int wordlength();
unsigned int rightrot(unsigned int x, int n);

int main() {
  printf("0x%x\n", rightrot(0x1AA, 3));
  return 0;
}

unsigned int rightrot(unsigned int x, int n) {
  int rbit;
  while (n-- > 0) {
    rbit = (x & 1) << (wordlength() -1);
    x = x >> 1;
    x = x | rbit;
  }
  return x;
}

// 计算出计算机所使用的字长
int wordlength() {
  int i;
  unsigned int v = (unsigned int) ~0;
  for (i = 1; (v = v >> 1) > 0; i++);
  return i;
}
