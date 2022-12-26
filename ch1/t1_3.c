
#include <stdio.h>

// 华氏温度和摄氏温度对照

main() {
  int fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;
  // 1.3 转换表顶部打印标题
  printf("华氏温度和摄氏温度对照表\n");
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }
}