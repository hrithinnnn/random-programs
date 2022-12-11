#include<stdio.h>
#include<sys/stat.h>
//#include<sys/types.h>
#include<time.h>
//#include<fcntl.h>
#include<dirent.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
//#include<string.h>
#include<stdlib.h>
#include<sys/time.h>
typedef struct queue{
  int front;
  int rear;
  int arr[100];
}queue;
queue* init(queue* q){
  q->front=0;
  q->rear=-1;
  memset(q->arr,-1,100);
  return q;
}

void enqueue(queue* q,int x){
  q->arr[++q->rear]=x;
}
int dequeue(queue* q){
  int y= q->arr[q->front++];
  return y;
}

int main(int argc, char* argv[]){
  queue* q=(queue*)malloc(sizeof(queue));
  init(q);
for(int i=0;i<12;i++){
  enqueue(q,rand()%10);
}
  for(int i=q->front;i<=q->rear;i++){
    printf("%d ",q->arr[i]);
  }
for(int i=0;i<4;i++){
  printf("\ndequeue: %d",dequeue(q));
}
 printf("\n");
 for(int i=q->front;i<=q->rear;i++){
    printf("%d ",q->arr[i]);
  }
}
  

