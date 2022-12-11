#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

int main(){
    char message[100];
    int id=shmget(123,sizeof(message),IPC_CREAT|00666);
    shmat(id,0,0);
    while(1){
    message[0]='\0';
    printf("you: ");
    scanf("%[^\n]s",message);
    getchar();
    if(strcmp(message,"bye")==0){
        break;
    }
    while(message[0]==0);
    printf("user 2: %s",message);
    sleep(1);
}

}