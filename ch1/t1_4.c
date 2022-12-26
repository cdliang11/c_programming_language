
#include <stdio.h>

// 摄氏温度和华氏温度对照表

main() {
  int fahr, celsius;
  int lower, upper, step;
  lower = -20;
  upper = 300;
  step = 20;
  celsius = lower;
  // 1.3 转换表顶部打印标题
  printf("摄氏温度和华氏温度对照表\n");
  while (celsius <= upper) {
    fahr = (celsius * 9) / 5 + 32;
    // celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", celsius, fahr);
    celsius += step;
  }
}