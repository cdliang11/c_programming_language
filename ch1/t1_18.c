
// 1.16 删除每个输入行末尾的空格和制表符，并删除完全是空格的行

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char str[], int maxline);
int move(char str[], int len);

int main() {
  char str[MAXLINE];
  int len = 0;
  while ((len = mygetline(str, MAXLINE)) != 0) {
    printf("%d\n", len);
    if (move(str, len) > 0)
      printf("%s", str);
  }
}

// 输入文本行
int mygetline(char str[], int maxline) {
  char c;
  int len = 0;
  c = getchar();
  for (; len < maxline-2 && c != '\n' && c != EOF; len++) {
    str[len] = c;
    c = getchar();
  }
  if (len == maxline - 2 || c == '\n') {
    str[len++] = '\n';
  }
  str[len] = '\0';
  return len;
}

// 删除末尾的制表符和空格
int move(char str[], int len) {
  while (str[len--] != '\n');
  for (len >= 0; str[len] == ' ' || str[len] == '\t'; len--);
  if (len >= 0) {
    str[++len] = '\n';
    str[++len] = '\0';
  }
  printf("%d\n", len);
  return len;
}
