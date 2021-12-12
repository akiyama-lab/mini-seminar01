#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 8

int main() {
  char *buf1, *buf2, *buf3;
  
  buf1 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf1 address: %p\n", buf1);
  // buf1 の解放（1回目）
  free(buf1);
  
  buf2 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf2 address: %p\n", buf2);
  // buf1 の解放（2回目）buf2 が解放されてしまう．
  free(buf1);
  
  buf3 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf3 address: %p\n", buf3);
 
  // buf3 に "0123456\0" をコピー
  strncpy(buf3, "0123456", 8);
  printf("buf3: %s\n", buf3);
  
  // buf2 の状態は？
  printf("buf2: %s\n", buf2);
  free(buf3);
}
