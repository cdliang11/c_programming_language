

// 1.13 编写一个程序,打印输入中单词长度的直方图

#include<stdio.h>

#define R 10
#define C 10
#define MAX 10 //单词最大长度

int main()
{
  int c, i, j, lon;
  int ndata[MAX];  // 记录单词长度出现次数
  char show[R][C];  // 图像数据组
  
  /*单词长度个数统计*/
  lon = 0; //单个单词长度
  for (i = 0; i < MAX; ++i)
    ndata[i] = 0;
  for (i = 0; i < R; ++i)
    for (j = 0; j < C; ++j)
      show[i][j] = 0;

  while((c = getchar()) != EOF) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  // 判断是否为单词字符
      lon++;  
    else {
      ndata[lon-1]++;
      lon = 0;
    }
  }

  // 单词长度个数垂直直方图绘制
  printf("\n直方图如下\n");
  for (i = 0; i < MAX; i++) {  // 图像数据载入
    while(ndata[i] > 0) {
      show[i][ndata[i]] = '*';
      ndata[i]--;
    }
  }
  for (i = 0; i < R; ++i) { // 图像数据遍历输出
      for (j = 0; j < C; ++j) {
        if(j == 0)printf("%d",i);
        else printf("%c",show[i][j]);
      }
      printf("\n");
  }
  return 0;
}
