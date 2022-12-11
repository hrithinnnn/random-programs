#include<stdio.h>
#include<sys/stat.h>
//#include<sys/types.h> 
#include<time.h> 
//#include<fcntl.h> 
#include<dirent.h>
//#include<string.h>
int main(int argc, char * argv[]) {
int t = 1, done;
DIR * dir;
struct dirent * ent;
if ((dir = opendir(argv[1])) == NULL) {
printf("Unable to open\n");
return 0;
}
if (argc == 2) {
while ((ent = readdir(dir)) != NULL)
printf("%s\n", ent -> d_name);
}
return (0);
}
