#include<stdio.h>
#include<malloc.h>
typedef struct stack{
    int top;
    int arr[100];
} stack;



void push(stack* s,int data)
{
    s->arr[s->top++]=data;
    //s->top+=1;
}

int pop(stack *s){
    
    //s->top-=1;
   // printf("%d",s->top);
    int temp=s->arr[--s->top];
    //s->top-=1;
    return temp;
}

void display(stack* s){
    for(int i=0;i<s->top;i++){
        printf("%d, ", s->arr[i]);
    }
    printf("\n");
}
void init(stack* s){
    s->top=-1;
}

void main(){
// stack* s= (stack*)malloc(sizeof(stack));
//   init(s);
//   push(s,5);
//   push(s,10);
//   display(s);
//   printf("%d \n", pop(s));
//   //pop(s);
//  display(s);
//  push(s,15);
//  display(s);
//  printf("%d \n", pop(s));
//  printf("%d \n", pop(s));
//  display(s);
stack s1={100,{69,12,0}};
stack* s= (stack*)malloc(sizeof(stack));
s=&s1;
printf("%d %d \n",s->top,s1.top);
init(s);
printf("%d %d %d", s1.top, s->top,s1.arr[1]);


} 