#ifndef _tester_
#define _tester_

#include <stdio.h>
#include "affine.h"
#include "Polybius.h"
#include "railfence.h"
#include "hill.h"
#include "playfair.h"

void test()
{
    fflush(stdin);
    int i=0;
    char name[100];
    char ch[1000];
    printf("enter file name");
    gets(name);
    FILE *fp ;
    fp = fopen("sample.txt","r") ;
    if (fp==NULL)
    {
     printf("file empty");
    }
do
  {
  ch[i] = getc(fp);
  i++;
  } while (ch[i]!= EOF)  ;

   printf("content : %s",ch);

testaffine(ch);
testpoly(ch);
testrailfencecipher(ch);
testplayfair(ch);
fclose(fp);

  printf("ENCRYPTION SUCCESSFULL");
}

#endif
