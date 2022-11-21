#include <stdio.h>
#include <assert.h>


//int atoi(char str[]) {
//  int i, n = 0;
//  for (i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
//    n = 10 * n + (str[i] - '0');
//  }
//  return n;
//}


#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int atoi(char *str) {
  assert(str);
  if (*str == '\0') return 0;
  while (*str == ' ') str++;
  int flag = 1;
  if (*str == '+') str++;
  else if (*str == '-') {
    flag = -1;
    str++;
  } 
  long long n = 0;
  while (*str >= '0' && *str <= '9') {
    n = n * 10 + flag * (*str - '0');
    if (n > INT_MAX || n < INT_MIN) return  0;
    str++;
  }
  if (*str == '\0') return (int)n;
  return (int)n;
}

int main(){
  char str[3] = {'-', '1', '2'};
  printf("%d", atoi(str));
  return 0;
}
