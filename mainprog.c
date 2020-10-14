#include <stdio.h>
#include "affine.h"
#include "Polybius.h"
#include "railfence.h"
#include "hill.h"
#include "playfair.h"
#include "tester.h"

int main()
{
int x;

printf("\n############### Comparative Study on Ciphers ################");
printf("\n############### M I N O R  P R O J E C T ################");

while(1)
{
printf("\n__________________________________________________________\n");
printf("Press '1' for Affine Cipher\n");
printf("Press '2' for Polybius Cipher\n");
printf("Press '3' for Railfence Cipher\n");
printf("Press '4' for Hill Cipher \n");
printf("Press '5' for Playfair Cipher \n");

printf("Press '6' to encrypt a text file \n");

printf("Press '0' for Exit\n");

printf("__________________________________________________________\n");
scanf("%d",&x);
printf("__________________________________________________________\n");
if(x==1)
{
printf("Affine Cipher\n");
printf("__________________________________________________________\n");
affine();
}
else if(x==2)
{
printf("Polybius Cipher\n");
printf("__________________________________________________________\n");
poly();
}
else if(x==3)
{printf("Railfence Cipher\n");
printf("__________________________________________________________\n");
railfencecipher();
}

else if(x==4)
{
printf("Hill Cipher\n");
printf("__________________________________________________________\n");
hillcypher();
}

else if(x==5)
{
printf("Playfair Cipher\n");
printf("__________________________________________________________\n");
playfair();
}

else if(x==6)
{
printf("Playfair Cipher\n");
printf("__________________________________________________________\n");
test();
}

else if(x==0)
{
printf("__________________________________________________________\n");
printf("Thank you for using program!\n");
printf("__________________________________________________________\n");
break;
}
else
{
printf("__________________________________________________________\n");
printf("Invalid Input!\n");
printf("__________________________________________________________\n");
}
}
return 0;
}
