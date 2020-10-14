#ifndef _hill_
#define _hill_


#include <math.h>
#include<time.h>
float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

void encryption();    //encrypts the message
void getKeyMessage();    //gets key and message from user
void inverse();        //finds inverse of key matrix

void hillcypher() {
    fflush(stdin);
    getKeyMessage();
    encryption();
    printf("\n");
}

void encryption() {
    int i, j, k;
clock_t begin=clock();
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

    clock_t end=clock();
    printf("\nEncrypted string is: ");
    for(i = 0; i < 3; i++)
        printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));
double time_spent=0;
time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
printf("\n");
printf("Time taken by processor is %f seconds",time_spent);
printf("\n");
}

void getKeyMessage() {
    int i, j;
    char msg[3];

    printf("Enter 3x3 matrix for key (It should be inversible):\n");

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
            c[i][j] = a[i][j];
        }

    printf("\nEnter a 3 letter string: ");
    scanf("%s", msg);

    for(i = 0; i < 3; i++)
        mes[i][0] = msg[i] - 97;
}

void inverse() {
    int i, j, k;
    float p, q;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }

    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];

            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];

    printf("\n\nInverse Matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%d ", b[i][j]);

        printf("\n");
    }
}

#endif
