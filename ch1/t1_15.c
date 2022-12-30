
// 1.15 用函数实现温度计算

#include <stdio.h>

// 华氏温度和摄氏温度对照

float fahr_celsius(float fahr) {
  return 5.0 * (fahr - 32.0) / 9.0;
}

float celsius_fahr(float celsius) {
  return (celsius * 9.0) / 5.0 + 32.0;
}

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
    celsius = fahr_celsius(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr += step;
  }
}