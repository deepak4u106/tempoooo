/**
 *      file    :  main.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 28 08:32:20  IST
 *      lastMod :  Wednesday 28 April 2021 08:32:20 AM IST
 **/

#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

int main()
{
  init();
  int pret,i,fret;
  proc *pr; // struct with pipe and request struct
  pr = (proc*)malloc(sizeof(proc));

  if(!pr)
  {
    perror("malloc");
    (*fptr[0])((void*)"failure");

  }
  printf("%s : %s PID : %d PPID : %dBegin\n",__FILE__,__func__,getpid(),getppid());
  pr->pipe = (int*)(*fptr[3])(0); // creatInfra

  for(i = 0 ; i < 3 ; i++)
  {
    fret = fork();
    printf("FORK RETURN : %d\n", fret);
    switch(fret)
    {
      case -1:
        perror("fork");
        (*fptr[0])((void*)"failure");
      case 0:
        printf("------------- C H I L D -- S T A R T-----------------");
        (*fptr[1])((void*)pr); //childTask
        break;
      default:
        printf("------------- P A R E N T -- S T A R T-----------------");
        (*fptr[2])((void*)pr); //parentTask
    }

  }



  printf("%s : End\n",__func__);
  return 0;
}    

