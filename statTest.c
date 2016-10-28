#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



int main(){
  struct stat curStats;
  int err = stat("statTest.c", &curStats);
  printf("Statted file success: %d\n\n", err);
  
  printf("Filesize: %d\n",curStats.st_size);
  //bitwise & with 0777 - octal 111s, three times
  printf("Permissions: %o\n", curStats.st_mode & 0777);
  printf("Last Access: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  return 0;
}
