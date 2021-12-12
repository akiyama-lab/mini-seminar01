#include <stdio.h>

int func(int a, int b) {
  int c = 1;
  int d = 2;
  char str[] = "11111";

  // 何らかの処理
  printf("%s\n", str);
  return (a + b + c + d);
}

int main() {
  int a = 1;
  int b = 2;
  int c;

  // 関数呼び出し
  c = func(a, b);
  // 何らかの処理
  printf("%d\n", c);
  return 0;
}
