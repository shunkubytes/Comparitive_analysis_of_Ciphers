#ifndef _affine_
#define _affine_

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int CalcGCD(int);
void affine()
{
 int i,j,k,gcd,alpha,beta,numstr[100],numcipher[100];
 char str[100],cipher[100];
 fflush(stdin);
 printf("Enter a string\n");
 gets(str);

 //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
  else
  {
   str[j]=' ';
   j++;
  }
 }
 str[j]='\0';
 printf("Entered string is : %s \n",str);
 printf("Enter Alpha value and must be between 1 and 25 both included\n");
 scanf("%d",&alpha);
 //Checking conditions
 if(alpha<1 || alpha>25)
 {
  printf("Alpha should lie in between 1 and 25\nSorry Try again !\n");
  exit(0);
 }
 gcd=CalcGCD(alpha);
 if(gcd!=1)
 {
  printf("gcd(alpha,26)=1 but \n gcd(%d,26)=%d\nSorry Try again !\n",alpha,gcd);
  exit(0);
 }
 printf("Enter Beta value and must be between 0 and 25 both included\n");
 scanf("%d",&beta);
 if(beta<0 || beta>25)
 {
  printf("Beta value should lie between 0 and 25\nSorry Try again !\n");
  exit(0);
 }
 //Conditions Over
 //Program Starts
 //Storing string in terms of ascii and to restore spaces I used -20
 clock_t begin=clock();
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
  else
  numstr[i]=-20;
 }
 //Ciphering Process
    //If numcipher is more than 25 .We need to convert and ensure that lie in between 0 and 25.(indicating Alphabets)
    //A-0,B-1,C-2,.....Y-24,Z-25
    printf("Affine Cipher text is\n");
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=((alpha*numstr[i])+beta)%26;
          printf("%c",(numcipher[i]+'A'));
     }
     else
     {
          printf(" ");
     }
    }
    clock_t end=clock();
double time_spent=0;
time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
printf("\n");
printf("Time taken by processor is %f seconds",time_spent);
printf("\n");
 }

int CalcGCD(int alpha)
{
 int x;
   int temp1=alpha;
   int temp2=26;

     while(temp2!=0)
      {
        x=temp2;
        temp2=temp1%temp2;
        temp1=x;
      }
     return(temp1);
}

void testaffine(char str[])
{
    fflush(stdin);
 int i,j,k,gcd,alpha=9,beta=5,numstr[100],numcipher[100];
 char cipher[100],result[1000];

  //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
  else
  {
   str[j]=' ';
   j++;
  }
 }
 str[j]='\0';
 //Checking conditions
 if(alpha<1 || alpha>25)
 {
  printf("Alpha should lie in between 1 and 25\nSorry Try again !\n");
  exit(0);
 }
 gcd=CalcGCD(alpha);
 if(gcd!=1)
 {
  printf("gcd(alpha,26)=1 but \n gcd(%d,26)=%d\nSorry Try again !\n",alpha,gcd);
  exit(0);
 }
 if(beta<0 || beta>25)
 {
  printf("Beta value should lie between 0 and 25\nSorry Try again !\n");
  exit(0);
 }
 //Conditions Over
 //Program Starts
 //Storing string in terms of ascii and to restore spaces I used -20
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
  else
  numstr[i]=-20;
 }
 //Ciphering Process
    //If numcipher is more than 25 .We need to convert and ensure that lie in between 0 and 25.(indicating Alphabets)
    //A-0,B-1,C-2,.....Y-24,Z-25
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=((alpha*numstr[i])+beta)%26;
         result[i]=(numcipher[i]+'A');
     }
     else
     {
          result[i]=" ";
     }
    }
    FILE *fp ;
    fp = fopen("affine.txt","a+") ;
    i=0;
      do
    {
     fputc(result[i],fp);
     i++;
    }while(result[i]!='\0');
     fclose(fp);
 }

#endif /* _MY_HEADER_H_ */
