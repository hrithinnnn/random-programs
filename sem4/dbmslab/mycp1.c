#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h>
#include<sys/wait.h> 
#include<fcntl.h>
int main(int argc, char * argv[]) {
if (argc == 3) {
int file1 = open(argv[1], O_RDONLY, 0);
int file2 = open(argv[2], O_WRONLY);
if (file1 == -1) {
printf("SOURCE FILE DOESNT EXIST!");
if (file2 != -1)
close(file2);
}

if (file2 == -1) {
if ((creat(argv[2], O_WRONLY)) == -1) {
printf("Error in creating file!");
} else {
char buffer[1000];
int x = read(file1, buffer, 50);
write(file2, buffer, x);
}
} else {
char buffer[1000];
read(file1, buffer, 100);
printf("%s", buffer);
write(file2, buffer, 100);
}
if (file1 != -1)
close(file1);
if (file2 != -1)
close(file2);
}}

