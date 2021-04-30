/**
 *      file    :  readRequest.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 29 03:47:27  IST
 *      lastMod :  Thursday 29 April 2021 03:47:27 PM IST
 **/

#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* readRequest(void* arg)
{
  printf("%s : Begin\n",__func__);

  int ret,rfd;
  proc *pr = (proc*)arg;
  request *r = (request*)malloc(sizeof(request));

  rfd = *(pr->pipe + 0);
  
  printf("PIPE 0 %d\n", *(pr->pipe + 0));
  
  if(!r)
  {
    perror("malloc");
    (*fptr[0])((void*)"failure");
  }

  ret = read(rfd,r,sizeof(request));

  printf("Number of bytes to be read %d\n", ret);
  if(ret == -1)
  {
    perror("read");
    (*fptr[0])((void*)"failure");
  }

  printf("Number of bytes to be read : %d\n", ret);
  printf("%s : End\n",__func__);
  return 0;
}    




