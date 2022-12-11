#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<dirent.h>
#include<string.h>
int main(int argc, char *argv[])
{
if (argc > 4)
printf("Too many arguments\n");
else if (argc < 2)
printf("Two arguments required\n");
else
{

int file = open(argv[2], O_RDONLY);
if (file == -1)
printf("File does not exist\n");
else
{
if (argc == 3)
{
char line[100], buf[1024];
int l = 0, i = 0, nr;
int count = 0;
nr = read(file, buf, 1024);
close(file);
while (l < nr)
{
for (i = 0; buf[l] != '\n' && l < nr; i++, l++)
{
line[i] = buf[l]; 
}
line[i] = '\0';
l++;
if (strstr(line, argv[1]))
printf("%s\n", line);
}
}
else if (argc > 3 && strcmp(argv[3], "-c")==0)
{
printf("Grep -c\n");
char line[100], buf[1024];
int l = 0, i = 0, nr, count = 0;
nr = read(file, buf, 1024);
close(file);
while (l < nr)
{
for (i = 0; buf[l] != '\n' && l < nr; i++, l++)
{
line[i] = buf[l]; 
}
line[i] = '\0';
l++;
if (strstr(line, argv[1]))
{
count++;
}}
printf("%d\n", count);
}}}}

