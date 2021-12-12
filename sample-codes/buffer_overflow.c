#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 16

int main() {
  char *buf1, *buf2;
  
  buf1 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf1 address: %p\n", buf1);

  buf2 = (char *)malloc(sizeof(char) * BUF_SIZE);
  printf("buf2 address: %p\n", buf2);
  
  // buf1 に "01234567890123456789\0" をコピー
  strncpy(buf1, "01234567890123456789", 21);
  
  // buf1, buf2 の状態は？
  printf("buf1: %s\n", buf1);
  printf("buf2: %s\n", buf2);
  free(buf1);
  free(buf2);
}
