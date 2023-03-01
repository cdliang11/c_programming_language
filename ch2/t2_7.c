

// 2.7 invert(x, p, n), 从p为开始的n个位求反

#include <stdio.h>

int invert(int x, int p, int n);

int main() {
  int x, p, n;
  scanf("%d %d %d", &x, &p, &n);
  printf("%d\n", invert(x, p, n));
  return 0;
}

int invert(int x, int p, int n) {
  // p开始的n位为1，其余为0，求异或
  return x ^ (~(~0<<n) << (p+1-n));
}
