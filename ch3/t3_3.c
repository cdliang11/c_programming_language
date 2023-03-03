
// 编写函数expand(s1, s2)
// 将字符串s1中类似于a-z一类的速记符号在字符串s2中扩展为等价的完整列表abc...xyz

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expand(char *s1, char *s2);

int main() {
  char *s1;
  char *s2;
  s1 = (char*)malloc(100*sizeof(char));
  s2 = (char*)malloc(100*sizeof(char));
  scanf("%s", s1);
  expand(s1, s2);
  printf("%s\n", s2);
  return 0;
}

void expand(char *s1,char*s2)
{
  int i,j = 0,k;
  for(i = 0; s1[i] != '\0'; i++)
  {
    if(s1[i] == '-')
    {
      if(s1[i-1]>='0' && s1[i+1]<='9' && s1[i-1] < s1[i+1])
      {
        for(k = 0; k < s1[i+1]-s1[i-1]-1; k++)
          s2[j++] = s1[i-1] + k + 1;
      }
      else if(s1[i-1]>='a' && s1[i+1]<='z' && s1[i-1] < s1[i+1])
      {
        for(k = 0; k < s1[i+1]-s1[i-1]-1; k++)
          s2[j++] = s1[i-1] + k + 1;
      }
      else if(s1[i-1]>='A' && s1[i+1]<='Z' && s1[i-1] < s1[i+1])
      {
        for(k = 0; k < s1[i+1]-s1[i-1]-1; k++)
          s2[j++] = s1[i-1] + k + 1;
      }
      else
        s2[j++] = s1[i];
    }
    else
      s2[j++] = s1[i];
  }
  s2[j] = '\0';
}
