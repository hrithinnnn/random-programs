 #define MAX_SIZE 100
#include<stdio.h> 
int main() {
    int t;
    int a[MAX_SIZE];
    int size=0;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
      int count = 0;
      size=0;
        for(int i=0;i<MAX_SIZE;i++) {
        scanf("%1d",&a[i]); 
            if(a[i]==0||a[i]==1) {
             size++;
            }
            else {
                break;
        }
    }
  
  
    if(size<4) {
        printf("%d\n",0);
       }
    else {
           for(int i=0;i<size-4;i++) {
      
                if((a[i]==1)&&(a[i+1]==0)&&(a[i+2]==1)&&(a[i+3]==0)) {
                    count++;
            }
        }
        printf("%d\n",count);
       }
    }
    return 0;
}

