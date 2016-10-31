#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void printPerms(int binData){
  int n;
  printf("-");
  for (n = 8; n >= 0; n--){
    if ((n >> 8) && 1){//get the relevant digit
      if (n % 3 == 2)
        printf("r");
      if (n % 3 == 1)
        printf("w");
      if (n % 3 == 0)
        printf("x");
    }
    else {
      printf("-");
    }
  }
  printf("\n");
}

int main(){
  struct stat curStats;
  struct tm st = *localtime(&curStats.st_atime);
  int err = stat("statTest.c", &curStats);
  printf("Statted file success: %d\n\n", err);
  
  long remSize = curStats.st_size;
  //printf("Filesize: %d\n",curStats.st_size);
  int gigs =  remSize / (1024 * 1024 * 1024);
  remSize -= gigs * (1024 * 1024 * 1024);
  int megs = remSize / (1024 * 1024);
  remSize -= megs * (1024 * 1024);
  int kibs = remSize / 1024;
  remSize -= kibs * 1024;
  printf("Filesize: %d GB, %d MB, %d KB, %d B \n", gigs, megs,kibs, remSize);
  
  //bitwise & with 0777 - octal 111s, three times
  //printf("Permissions: %o\n", curStats.st_mode & 0777);
  printPerms(curStats.st_mode & 0777);
  
  printf("Last Access: %s", asctime(gmtime(&curStats.st_atime)));
  return 0;
}
