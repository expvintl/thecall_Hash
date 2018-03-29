#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#define kkey 0x73e2
//算法
short dohash(const char* thecall)
{
  char rootcall[10];     // need to copy call to remove ssid from parse
  char *p1 = rootcall;
  while ((*thecall != '-') && (*thecall != 0)) *p1++ = toupper(*thecall++);
    *p1 = 0;
  short hash = kkey;     // initialize with the key value
  short i = 0;
  short len = strlen(rootcall);
  char *ptr = rootcall;
  while (i < len) {         // loop through the string two bytes at a time
    hash ^= (*ptr++)<<8;   // xor high byte with accumulated hash
    hash ^= (*ptr++);     // xor low byte with accumulated hash
    i += 2;
  }
  return hash & 0x7fff; // mask off the high bit so number is always positive
}
int main(int agrc, char *argv[]) {
  printf("%d", dohash("这里填呼号"));
}
