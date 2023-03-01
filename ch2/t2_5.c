
// 2.5 编写any(s1, s2), 将s2中任一字符在s1中第一次出现的位置返回
//     如果不包含则返回-1

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
  char str1[80], str2[80];
  printf("输入s1 和 s2: ");
  scanf("%s %s", str1, str2);
  printf("%s %s\n", str1, str2);
  printf("%d\n", any(str1, str2));
  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;
  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++) {};
    if (s2[j] != '\0') {
      return i;
    }
  }
  return -1;
}
