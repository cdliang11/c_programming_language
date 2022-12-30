
// 1.16 打印长度大于80的行


#include <stdio.h>
#define MAXLINE 1000 //允许输入行的最大长度
#define MINLEN 80

int get_Line(char line[], int maxline);

int main() {
  int len; //当前行长度
  int line_num = 0;
  char line[MAXLINE];
  while ((len = get_Line(line, MAXLINE)) > 0) {
    if (len > MINLEN) {
      printf("%s", line);
    }
  }
  return 0;
}

// getline函数： 读一行读入到S中，并返回其长度
int get_Line(char s[], int lim) {
  int c, i, j;
  j = 0;
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if(i < lim - 2) {
      s[j++] = c;
    }
  } //这里getline修改后，i可以大于lim的限制，只计数，不保存字符
  if(c == '\n')
  {
    s[j++] = c;
    ++i;
  }
  s[j] = '\0';
  return i;
}
