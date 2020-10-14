#ifndef _Polybius_
#define _Polybius_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
void poly()
{
 int i,j,poly[26],x,k;
 char str[1000];
 fflush(stdin);
 printf("Enter a sentence\n");
 gets(str);
i=0;
 while(str[i]!='\0')
 {
  if((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))
  {
   printf("Enter only alphabets and space\n");
   exit(0);
  }
  i++;
 }
 x=0;
 k=11;
 //Assigning Polybius Square numbers to alphabets
clock_t begin=clock();
for(i=0;i<=25;i++)
{
 if(i<=8)
 {
      if(i%5==0&&i!=0)
   {
  k+=5;
  poly[x]=k++;

    }
   else{
  poly[x]=k++;

      }
 }
 if(i>=10)
 {
      if(i%5==0&&i!=0)
   {

  poly[x]=k++;
   k+=5;

    }
   else{
  poly[x]=k++;

      }
 }
 if(i==9)
 {
  poly[x]=24;
 }


  x++;
}
i=0;
printf("Encrypted Code using Polybius Square Cipher \n");
while(str[i]!='\0')
  {
 if(!((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
 {
   if(str[i]>='A'&&str[i]<='Z')
   {
    printf("%d ",poly[str[i]-'A']);
   }
     if(str[i]>='a'&&str[i]<='z')
     {
      printf("%d ",poly[str[i]-'a']);
     }

 }

    if(str[i]==' ')
    {
      printf("%c",str[i]);
    }

   i++;
  }
  clock_t end=clock();
double time_spent=0;
time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
printf("\n");
printf("Time taken by processor is %f seconds",time_spent);
  printf("\n");

}


void testpoly(char str[])
{
 int i,j,poly[26],x,k;
 char result[1000];
i=0;
 while(str[i]!='\0')
 {
  if((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))
  {
   printf("Enter only alphabets and space\n");
   exit(0);
  }
  i++;
 }
 x=0;
 k=11;
 //Assigning Polybius Square numbers to alphabets
for(i=0;i<=25;i++)
{
 if(i<=8)
 {
      if(i%5==0&&i!=0)
   {
  k+=5;
  poly[x]=k++;

    }
   else{
  poly[x]=k++;

      }
 }
 if(i>=10)
 {
      if(i%5==0&&i!=0)
   {

  poly[x]=k++;
   k+=5;

    }
   else{
  poly[x]=k++;

      }
 }
 if(i==9)
 {
  poly[x]=24;
 }


  x++;
}
i=0;
while(str[i]!='\0')
  {
 if(!((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
 {
   if(str[i]>='A'&&str[i]<='Z')
   {
    result[i]=(poly[str[i]-'A']);
   }
     if(str[i]>='a'&&str[i]<='z')
     {
      result[i]=(poly[str[i]-'a']);
     }

 }

    if(str[i]==' ')
    {
      result[i]=str[i];
    }

   i++;
  }
  FILE *fp ;
    fp = fopen("polybius.txt","a+") ;
    i=0;
     do
    {
     fputc(result[i],fp);
     i++;
    }while(result[i]!='\0');
     fclose(fp);

}

#endif
