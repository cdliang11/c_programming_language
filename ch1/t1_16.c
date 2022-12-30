
// 1.16 修改打印最长文本行的程序，使之可以打印任意长度的输入行的长度


#include <stdio.h>
#define MAXLINE 1000 //允许输入行的最大长度

int get_Line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len; //当前行长度
  int max; //目前为止发现的最长行的长度
  char line[MAXLINE]; //当前的输入行
  char longest[MAXLINE]; //用于保存最长的行

  max = 0;
  while ((len = get_Line(line, MAXLINE)) > 0)
    printf("line's len %d ,  line: %s", len, line);
  if(len > max) {
    max = len;
    copy(longest, line);
  }
  if(max > 0)
    printf("longest's len %d ,longest: %s\n", max, longest);
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

//copy 函数：将from复制到to；这里假定to足够大
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
  ++i;
}
