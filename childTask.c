/**
 *      file    :  childTask.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 28 11:02:32  IST
 *      lastMod :  Wednesday 28 April 2021 11:02:32 AM IST
 **/

#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* childTask(void* arg)
{
  printf("%s : Begin\n",__func__);

  int i,wfd1,rfd2;
  int* arr;
  char wfd[4];
  char rfd[4];

  proc *pr = (proc*)arg;


  wfd1 = *(pr->pipe + 1);
  rfd2 = *(pr->pipe + 2);

  printf("WRITE FILE DESCRIPTOR : %d\n",wfd1);
  printf("READ FILE DESCRIPTOR : %d\n",rfd2);

  sprintf(wfd,"%d",wfd1);
  sprintf(rfd,"%d",rfd2);

  execl("./rc1","rc1",wfd,rfd,NULL);
  


  
  printf("%s : End\n",__func__);
  return 0;
}    

