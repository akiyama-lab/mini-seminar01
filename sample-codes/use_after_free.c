#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 8

int main() {
  char *buf1, *buf2, *buf3;

  buf1 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf1 address: %p\n", buf1);
  free(buf1);
  // これ以降のbuf1はダングリングポインタであり，
  // その利用は use after free となる．

  buf2 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf2 address: %p\n", buf2);
 
  // buf2 に "0123456\0" をコピー
  strncpy(buf2, "0123456", 8);
  printf("buf2: %s\n", buf2);
  
  // buf1 に "6543210\0" をコピー
  strncpy(buf1, "6543210", 8);
  printf("buf1: %s\n", buf1);

  // buf2 の状態は？
  printf("buf2: %s\n", buf2);
  free(buf2);
}
