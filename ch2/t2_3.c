
// 编写htoi(s)程序，将十六进制数字组成的字符串转换为等价的整型
// 字符串中允许包含的数字包括：0-9, a-f, A-F

#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int main() {
  char s[20];
  printf("请输入十六进制的数\n");
  char c;
  int i = 0;
  while ((c = getchar()) != EOF && (c != ' ') && (c != '\n')) {
    s[i++] = c;
  }
  s[i] = ' ';
  printf("%d\n", htoi(s));
  return 0;
}

int htoi(char s[]) {
  int start=0, end;
  int res = 0;
  if (s[0] == '0' && (s[1] == 'x' || s[1] =='X')) {
    start = 2;
  }
  int j = 0;
  while (s[j++] != ' ') {}
  end = j - 2;
  for (int i = 1; end >= start; i = i * 16) {
    if (s[end] >= '0' && s[end] <= '9') {
        res = res + (s[end] - '0') * i;
    } else if (s[end] >= 'a' && s[end] <= 'f') {
        res = res + (s[end] - 'a' + 10) * i;
    } else if (s[end] >= 'A' && s[end] <= 'F') {
        res = res + (s[end] - 'A' + 10) * i;
    }
    end--;
  }
  return res;
}
