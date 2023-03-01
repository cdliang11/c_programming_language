
// 在不使用&& ||的条件下，编写一个和以下等价的循环语句
// for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++)
// s[i] = c;

for (i = 0; (i < lim - 1) * ((c = getchar()) != EOF) * (c != '\n'); ++i)
  s[i] = c;
