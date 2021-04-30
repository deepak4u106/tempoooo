/**
 *      file    :  parentTask.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 28 11:01:58  IST
 *      lastMod :  Wednesday 28 April 2021 11:01:58 AM IST
 **/

#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* parentTask(void* arg)

{
  printf("%s : Begin\n",__func__);

  proc* pr = (proc*)arg;

  int i;


    
  (*fptr[4])((void*)pr); //read request

  (*fptr[5])((void*)pr); //processReq


  
  printf("%s : End\n",__func__);
  return 0;
}    

