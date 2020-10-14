#ifndef _railfence_
#define _railfence_


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void railfencecipher()
{
 int i,j,len,rails,count,code[100][1000];
    char str[1000];
     fflush(stdin);
    printf("Enter a Secret Message\n");
    gets(str);
    len=strlen(str);
 printf("Enter number of rails\n");
 scanf("%d",&rails);
 clock_t begin=clock();
 for(i=0;i<rails;i++)
 {
  for(j=0;j<len;j++)
  {
   code[i][j]=0;
  }
 }
count=0;
j=0;
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
  //strcpy(code[i][j],str[j]);
  code[i][j]=(int)str[j];
  j++;
 }

}
else
{

 for(i=rails-2;i>0;i--)
 {
  code[i][j]=(int)str[j];
 j++;
 }
}

count++;
}

for(i=0;i<rails;i++)
{
 for(j=0;j<len;j++)
 {
  if(code[i][j]!=0)
  printf("%c",code[i][j]);
 }

}
clock_t end=clock();
double time_spent=0;
time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
printf("\n");
printf("Time taken by processor is %f seconds",time_spent);
printf("\n");
}

void testrailfencecipher(char str[])
{
 int i,j,len,rails=3,count,code[100][1000];
 char result[1000];
    len=strlen(str);
 for(i=0;i<rails;i++)
 {
  for(j=0;j<len;j++)
  {
   code[i][j]=0;
  }
 }
count=0;
j=0;
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
  //strcpy(code[i][j],str[j]);
  code[i][j]=(int)str[j];
  j++;
 }

}
else
{

 for(i=rails-2;i>0;i--)
 {
  code[i][j]=(int)str[j];
 j++;
 }
}

count++;
}
int k=0;
for(i=0;i<rails;i++)
{
 for(j=0;j<len;j++)
 {
  if(code[i][j]!=0)
  result[k]=code[i][j];
  k++;
 }

}
FILE *fp ;
    fp = fopen("railfence.txt","a+") ;
    i=0;
     do
    {
     fputc(result[i],fp);
     i++;
    }while(result[i]!='\0');
     fclose(fp);
 }


#endif /* _MY_HEADER_H_ */
