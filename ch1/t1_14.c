

// 1.14 打印输入中个字符出现频次的直方图
//      定义三种字符：1.字母 2. 空格制表符等 3. 其他

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int c, nletter, nwhite, nother, i;  // 定义字符，字母个数，空白个数，其他字符个数
  nletter=nwhite=nother=0;
  while((c = getchar()) != EOF) {
    if ((c >= 'A' && c <= 'Z') || (c >='a' && c<='z'))
      // 输入为字母
      ++nletter;
    else if (c == ' ' || c== '\t' || c=='\n')
      // 输入字符为空格或制表符或换行符
      ++nwhite;
    else
      ++nother;
  }
  printf("字母\t\t");            /*此五行为输出字母直方图*/
  for (i=1; i<=nletter; ++i)
    printf("*");
  printf("\n");
  printf("空格或制表符\t");              /*此五行为输出空白直方图*/
  for (i=1; i<=nwhite; ++i)
    printf("*");
  printf("\n");
  printf("其他字符\t");              /*此五行为输出其他字符直方图*/
  for (i=1; i<=nother; ++i)
    printf("*");
  printf("\n");
  return 0;
}
