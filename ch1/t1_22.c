

// 1-22 编写程序，将较长的行折成较短的行
// 这行位置是第n列之前的最后一个非空格之后

#include <stdio.h>

#define N 10   // 折行位置
#define TABINC 4

char line[N];

int detab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

int main() {
  int c, pos;
  pos = 0;
  while ((c = getchar()) != EOF) {
    line[pos] = c;
    if (c == '\t')
      pos = detab(pos);
    else if (c == '\n') {
      printl(pos);
      pos = 0;
    } else if (++pos >= N) {
      pos = findblnk(pos);
      printl(pos);
      pos = newpos(pos);
    }
  }
  return 0;
}

// 将制表符转换为空格
int detab(int pos) {
  line[pos] = ' ';
  for (++pos; pos < N && pos % TABINC != 0; ++pos)
    line[pos] = ' ';
  if (pos < N) return pos;
  else {
    printl(pos);
    return 0;
  }
}

// 打印改行
void printl(int pos) {
  int i;
  for (i = 0; i < pos; i++)
    putchar(line[i]);
  if (pos > 0) putchar('\n');
}

// 往前搜索一个空格，单词的完整性
int findblnk(int pos) {
  while (pos > 0 && line[pos] != ' ') --pos;
  if (pos == 0) return N; // 没找到空格
  else return pos + 1;
}

// 调整输入行的位置
int newpos(int pos) {
  int i, j;
  if (pos <= 0 || pos >= N)
    return 0;
  else {
    i = 0;
    for (j = pos; j < N; ++j) {
      // 将剩余的字符复制到新行折行开始处
      line[i] = line[j];
      ++i;
    }
    return i;
  }
}
