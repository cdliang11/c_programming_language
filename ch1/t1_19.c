

// 1-19: 编写reverse()函数，反转字符串

#include <stdio.h>

#define MAX_LINE 1024

int reverse(char s[]);
int mygetline(char s[], int maxline);
// 删除末尾换行符
void discardNewline(char s[]);

int main() {
  char line[MAX_LINE];
  while (mygetline(line, MAX_LINE) > 0) {
    discardNewline(line);
    reverse(line);
    printf("%s\n", line);
  }
  return 0;
}

int reverse(char s[]) {
  char ch;
  int i, j;
  for (j = 0; s[j] != '\0'; j++);
  --j;
  for (i = 0; i < j; i++) {
    ch = s[i];
    s[i] = s[j];
    s[j] = ch;
    --j;
  }
  return 0;
}

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

void discardNewline(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == '\n') s[i] = '\0';
  }
}