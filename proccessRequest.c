/**
 *      file    :  readRequest.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 29 03:47:27  IST
 *      lastMod :  Thursday 29 April 2021 03:47:27 PM IST
 **/

#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* proccessRequest(void* arg)
{
  printf("%s : %s Begin\n",__FILE__,__func__);

  int ret,wfd5,rfd6;

  char rsfd[4], wsfd[4];

  proc *pr;

  pr = (proc*)arg;

  ret = fork();

  switch(ret)
  {
    case -1:
      perror("fork");
      (*fptr[0])((void*)"failure");
    case 0:
      sprintf(wsfd,"%d",*(pr->pipe+5));
      sprintf(rsfd,"%d",*(pr->pipe+6));
      switch(pr->r->opr)
      {
        case '+':
          execl("./adder","adder",wsfd,rsfd,NULL);
          break;
        case '-':
          execl("./subtr","subtr",wsfd,rsfd,NULL);
          break;
        case '*':
          execl("./multi","multi",wsfd,rsfd,NULL);
          break;
        case '/':
          execl("./divid","divid",wsfd,rsfd,NULL);
          break;
        case '%':
          execl("./modul","modul",wsfd,rsfd,NULL);
          break;
      }
    default:
      printf("%s : %s Parent procces\n",__FILE__,__func__);


  }



  printf("%s : %s End\n",__FILE__,__func__);
  return (void*)pr;
}    

