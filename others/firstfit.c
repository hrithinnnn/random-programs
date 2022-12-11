#include<stdio.h>
#include<stdlib.h>

struct block{
    int status;
    int start;
    int end;
    int belongs_to;
    int size;
};

void insert_into(struct block b[],int *n,int pos,struct block newb)
{
    for(int i=(*n)-1;i>=pos;i--)
    {
        b[i+1]=b[i];
    }
    b[pos]=newb;
    (*n)=(*n)+1;
}

void delete_block(struct block b[],int *n,int pos)
{
    for(int i=pos;i<(*n)-1;i++)
    {
        b[i]=b[i+1];
    }
    (*n)=(*n)-1;
}

int main()
{
    int n_patitions;

    printf("Enter Number of partitions : ");
    scanf("%d",&n_patitions);

    struct block blocks[20];

    for(int i=0;i<n_patitions;i++)
    {
        scanf("%d %d",&blocks[i].start,&blocks[i].end);
        blocks[i].status=0;
        blocks[i].belongs_to=i;
        blocks[i].size=blocks[i].end-blocks[i].start;
    }

    int choice;
    do{
        printf("1.allocate    2.deallocate    3.compaction    4.display    5.exit\nenter choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            int p,p_size;
            printf("Enter process no : ");
            scanf("%d",&p);
            printf("Enter process size : ");
            scanf("%d",&p_size);


            for(int i=0;i<n_patitions;i++)
            {
                if(blocks[i].size>=p_size && blocks[i].status==0)
                {
                    struct block newb;
                    newb.size=p_size;
                    newb.start=blocks[i].start;
                    newb.end=blocks[i].start+newb.size;
                    newb.status=p;
                    newb.belongs_to=blocks[i].belongs_to;

                    blocks[i].start=newb.end;
                    blocks[i].size=blocks[i].end-blocks[i].start;
                    insert_into(blocks,&n_patitions,i,newb); 
                    if(blocks[i+1].size<=0 && blocks[i+1].status==0)
                        delete_block(blocks,&n_patitions,i+1);
                    
                    break; 
                }
            }
        }
        else if(choice==2)
        {
            int p;
            printf("Enter process no : ");
            scanf("%d",&p);

            for(int i=0;i<n_patitions;i++)
            {
                //printf("status : %d\n",blocks[i].status);
                if(blocks[i].status==p)
                {
                    printf("found\n");
                    blocks[i].status=0;
                    if(i!=n_patitions-1)
                    {
                        if(blocks[i+1].status==0 && blocks[i+1].belongs_to==blocks[i].belongs_to)
                        {
                            blocks[i].end=blocks[i+1].end;
                            delete_block(blocks,&n_patitions,i+1);
                        }
                    }
                    if(i!=0)
                    {
                        if(blocks[i-1].status==0 && blocks[i-1].belongs_to==blocks[i].belongs_to)
                        {
                            blocks[i].start=blocks[i-1].start;
                            delete_block(blocks,&n_patitions,i-1);
                        }
                    }
                    break;
                }
                
            }
        }
        else if(choice==3)
        {
            struct block blocks_com[20];
            int index=0;
            int free_size=0;
            int n_alloc=0;
            int n_free=0;
            int start=blocks[0].start;

            for(int i=0;i<n_patitions;i++)
            {
                if(blocks[i].status)
                {
                    blocks_com[index++]=blocks[i];
                    n_alloc++;
                    blocks_com[index-1].start=start;
                    blocks_com[index-1].end=start+blocks_com[index-1].size;
                    start+=blocks_com[index-1].size;
                }
                else
                    {free_size+=blocks[i].size; n_free++;}
            }
            
            struct block free_blk;

            n_patitions=n_alloc+1;

            free_blk.status=0;
            free_blk.start=blocks_com[index-1].end;
            free_blk.size=free_size;
            free_blk.end=free_blk.start + free_blk.size;
            blocks_com[index++]=free_blk;

            for(int i=0;i<n_patitions;i++)
            {
                blocks[i]=blocks_com[i];
            }

        }
        else if(choice ==4)
        {
            printf("\nMEMORY :\n");

            for(int i=0;i<n_patitions;i++)
            {
                printf("+-------");
            }
             printf("+\n");
            int n_free=0,n_alloc=0;
            for(int i=0;i<n_patitions;i++)
            {
                if(blocks[i].status)
                    {printf("|  P%d   ",blocks[i].status); n_alloc++;}
                else
                    { printf("|  H    "); n_free++;}
            }

            printf("|\n");
            for(int i=0;i<n_patitions;i++)
            {
                printf("+-------");
            }
            printf("+\n");
            for(int i=0;i<n_patitions;i++)
                printf("%d     ",blocks[i].start);

            printf("%d\n\n",blocks[n_patitions-1].end);

        }

        else if(choice ==5)
        {
            break;
        }
    }while(choice!=5);
}