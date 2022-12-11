#include<stdio.h>
#include<sys/stat.h>
//#include<sys/types.h> 
#include<time.h> 
//#include<fcntl.h> 
#include<dirent.h>
//#include<string.h>
int main(int argc, char *argv[]){
directory *directory;
struct dirent *ent;
if(argc<3){
printf("incorrect syntax\n");
return 0;
}
if((directory = opendir(argv[2])) == NULL){
printf("directory doesnt exist\n");
return 0;
}
if(argc==3){
directory = opendir(argv[2]);
while((ent = readdir(directory))!=NULL){
printf("%s\t",ent->d_name);
struct stat sbuf;
stat(ent->d_name,&sbuf);
if(sbuf.st_size==0){
printf("d");
}
if(sbuf.st_mode & S_IREAD){
printf("r");
}
if(sbuf.st_mode & S_IWRITE){
printf("w");}
if(sbuf.st_mode & S_IEXEC){
printf("x");
}
printf("\t%ld",sbuf.st_size);
printf("\t%s\n",ctime(&sbuf.st_ctime));
}
closedir(directory);
}

if(argc==2){
while((ent=readdir(directory)) != NULL)
printf("%s\n",ent->d_name);
}
}


