#include <stdio.h>

void strcat(char *s, char *t) {
  while (*s != '\0') s++;
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

int main() {
  char s[3] = {'a','b','c'};
  char t[2] = {'a','m'};
  strcat(s, t);
  printf("%s", s);
  return 0;
}
