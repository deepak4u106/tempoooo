/**
 *      file    :  creatInfra.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 28 11:09:42  IST
 *      lastMod :  Wednesday 28 April 2021 11:09:42 AM IST
 **/

#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* creatInfra(void* arg)
{
  printf("%s : Begin\n",__func__);
  int* arr;
  int i,pret;
  arr = (int*)malloc(sizeof(int)*8);
  if(!arr)
  {
    perror("malloc");
    (*fptr[0])((void*)"failure");
  }
  for(i = 0 ; i < 4 ; i++)
  {
    pret = pipe(arr + (i*2));
    if(pret == -1)
    {
      perror("pipe");
      (*fptr[0])((void*)"failure");
    }
  }


  printf("%s : End\n",__func__);
  return (void*)arr;
}    

