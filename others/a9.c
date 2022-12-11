#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE 100

int getFreeFrameCount();
int allocateFrames(int pid, int size);
void printFreeFrames();
void printProcesses();
int deallocateFrames(int pid);

typedef struct processStruct {
    int processID;
    int framesUsed[SIZE];
    int frameCount;
    int processSize;
} process;

int frameSize;
int memSize;
int frames[SIZE];
int frameCount;
process processes[SIZE];
int processCount = 0;

int main(void) {


    printf("Enter the physical memory size(KB): ");
    scanf("%d", &memSize);

    printf("Enter the size of each frame: ");
    scanf("%d", &frameSize);

    frameCount = ceil(memSize/frameSize);
    printf("Physical memory is divided into %d frames\n", frameCount);

    
    memset(frames, 1, sizeof(frames));

    int n = 10;
    for(int i = 0; i < n; i++) {
        int random = rand();
        frames[random % frameCount] = 0;
        //printf("Random: %d, array value: %d\n", random, random % frameCount);
    }
    printFreeFrames(frames, frameCount);
    allocateFrames(0, 3);
    printProcesses();
    printf("Deallocation\n");
    deallocateFrames(0);
    printProcesses();
    printFreeFrames(frames, frameCount);
}

int getFreeFrameCount() {
    int sum = 0;
    for(int i = 0; i < frameCount; i++) {
        if(!frames[i]) {
            sum++;
        }
    }
    return sum;
}


int allocateFrames(int pid, int size) {
    process p;
    p.processSize = size;
    p.frameCount = ceil(size/frameSize);
    p.processID = pid;
    if(getFreeFrameCount() < p.frameCount) {
        printf("Not enough frames available to allocate\n");
        return -1;
    }
    int j = 0;
    for(int i = 0; i < frameCount; i++) {
        if(frames[i] == 0) {
            p.framesUsed[j++] = i;
            frames[i] = 1;
            if(j == p.frameCount) {
                printf("Frames allocated successfully\n");
                processes[processCount++] = p;
                return 1;
            }
        }

    }
}

int deallocateFrames(int pid) {
    int pIndex;
    int found = 0;
    for(int i = 0; i < processCount; i++) {
        if(processes[i].processID == pid) {
            found = 1;
            pIndex = i;
            break;
        }
    }
    if(!found) {
        printf("Process not found!\n");
        return -1;
    }
    for(int i = 0; i < processes[pIndex].frameCount; i++) {
        frames[processes[pIndex].framesUsed[i]] = 0;
    }
    processes[pIndex].frameCount = 0; 
}

void printProcesses() {
    printf("Processes: \n");
    for (int i = 0; i < processCount; i++) {
        if(processes[i].frameCount != 0) {
            printf("Process id: P%d\n", processes[i].processID);
            for(int j = 0; j < processes[i].frameCount; j++) {
                printf("Page %d: Frame %d\n", j, processes[i].framesUsed[j]);
            }
            printf("\n");
        }
    }
    
}


void printFreeFrames() {
    printf("Free frames: ");
    for (int i = 0; i < frameCount; i++) {
        if(!frames[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
}