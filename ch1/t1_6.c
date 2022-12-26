
#include <stdio.h>

// c = (getchar() != EOF);
// 不为 EOF的时候 结果为 1
// 反之为 0

main() {
  int c;
  c = (getchar() != EOF);
  printf("%d\n", c);
}