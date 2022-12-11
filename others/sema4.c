#include<semaphore.h>
#include<stdio.h>
//#include<sys/sem.h>
#include<unistd.h>
void main(){
    int file1[3];
    int file2[5];
    for (int i=0;i<3;i++){
        file1[i]=rand()%100;
    }
    for (int i=0;i<5;i++){
        file2[i]=rand()%100;
    }
    printf("file 1\n");
    for (int i=0;i<3;i++){
        printf("%d->",file1[i]);
    }
    printf("\b\b  ");
    printf("\nfile2\n");
    for (int i=0;i<5;i++){
        printf("%d->",file2[i]);
    }
    printf("\b\b  ");
    }

    