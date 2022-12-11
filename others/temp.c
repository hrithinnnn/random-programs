#include<stdio.h>
int path[6];
int x=0;
// void test(int *front, int *rear,int a[]){
//     *front=*front+1;
//     printf("%d %d",*front, a[*front]);
//}
int par[100];

void init(int n) {
    for(int i = 0;i<n;i++) {

        par[i] = -1;
    }
}

int dfs(int adj[][6],int visited[], int i, int n){
//path[x++]=i;
// printf("%d", i);
visited[i]=1;
for(int j=0;j<n;j++){
    if(visited[j]==0&&adj[i][j]==1){
        // printf("%d %d \n", j, i);
        par[j] = i;
        dfs(adj,visited,j,n);
    }
}
//dfs(adj,visited,1);
}

void printPath(int adj[][6],int visited[], int n, int from, int to) {

    dfs(adj, visited, from, n);

    int i = to;
    int k = 0;

    do {

        printf("%d", i);
        i = par[i];
    } while(i!=from);

    printf("%d", from);

    // for(int c = 0; c<n;c++) {

    //     printf("%d", par[c]);
    // }
}

void main(){
    int n;
    scanf("%d",&n);
    // int front,rear ;
    // int a[100];
    // a[0]=1;
    // a[1]=10;
    // a[2]=20;
    // front=a[0];
    // rear=a[1];
    // //**front=&a[0];
    // //**rear=&a[2];
    // test(&front, &rear,a);
    // printf("\n%d %d",front, a[front]);
    int adj[6][6];
  
    int a,b;
    int visited[6];
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    do{
        scanf("%d %d",&a,&b);
        adj[a][b]=1;
        adj[b][a]=1;
    }while(a!=-1);
    
    //}
    // for(int i=0;i<n;i++){
    // for (int j=0;j<n;j++){
    // printf("%d",adj[i][j]);
    // }
    // printf("\n");
    // }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    init(n);
    printPath(adj, visited, n, 1, 2);
   // for(int i=0;i<6;i++){

   // if(visited[i])
//    init(n);
//    for(int i = 0; i < n; i++) {

//        printf("Starting from %d: ", i);

//         for(int i=0;i<n;i++){
//         visited[i]=0;
//     }

//        dfs(adj,visited,i,n);

//        printf("\n");
//    }
    //int i=-1;
    // for(int i=1;i<6;i++){
    //     if(visited[i]==0){
    //         dfs(adj,visited,i);
    //     }
    // }
   // }
// do{
//     i++;
//     printf(" %d",path[i]);
// }while(path[i]!=3);
}
    
