
// 编写escape(t,s)函数，将t复制到s中，并将换行符 制表符等转换为可见
// 编写具有相反功能的函数

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  char s[] = "ljalj";
  char t[] = "wu\tfsd\nfsd";
  escape(s, t);
  printf("%s\n", s);
  return 0;
}

void escape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; i++) {
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
    default:
        s[j++] = t[i];
        break;
    }
    s[j] = '\0';
  }
  return;
}

void unescape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; i++) {
    if (t[i] != '\\') {
      s[j++] = t[i];
    } else {
      switch (t[++i]) {
        case 'n':
          s[j++] = '\n';
          break;
        case 't':
          s[j++] = '\t';
          break;
        default:
          s[j++] = '\\';
          s[j++] = t[i];
          break;
      }
    }
    s[j] = '\0';
  }
  return;
}
