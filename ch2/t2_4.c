

// 2-4 重新编写squeeze()函数，将s1中任何和s2中字符匹配的字符删除

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
  char str1[80], str2[80];
  printf("输入s1 和 s2: ");
  scanf("%s %s", str1, str2);
  printf("%s %s\n", str1, str2);
  squeeze(str1, str2);
  printf("%s\n", str1);
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k, n;
  for (n = 0; s2[n] != '\0'; n++);
  for (i = k = 0; s1[i] != '\0'; i++) {
    for (j = 0; j < n && s2[j] != s1[i]; j++);
    if (s2[j] == '\0') s1[k++] = s1[i];
  }
  s1[k] = '\0';
}
