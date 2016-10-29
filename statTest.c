#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


int main(){
  struct stat curStats;
  struct tm st = *localtime(&curStats.st_atime);
  int err = stat("statTest.c", &curStats);
  printf("Statted file success: %d\n\n", err);
  
  printf("Filesize: %d\n",curStats.st_size);
  //bitwise & with 0777 - octal 111s, three times
  printf("Permissions: %o\n", curStats.st_mode & 0777);

  
  printf("Last Access: %s", asctime(gmtime(&curStats.st_atime)));
  return 0;
}
