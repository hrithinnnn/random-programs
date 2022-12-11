#include<stdio.h>
void main(){
    for(int i=0;i<25;i++){
        printf("%d ",(87+(i*i))%7);
    }
}