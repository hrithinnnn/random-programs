#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void list(Queue queue);
void spool(Queue queue, int jobId);
int print(Queue queue);

int main(void) {
    Queue queue = makeNewQueue(5);
	
	printf("spool 1: ");
	spool(queue, 1);
	list(queue);

	printf("spool 2: ");
	spool(queue, 2);
	list(queue);

	printf("spool 3: ");
	spool(queue, 3);
	list(queue);

	printf("spool 4: ");
	spool(queue, 4);
	list(queue);


	printf("print: ");
	print(queue);
	list(queue);

	printf("print: ");
	print(queue);
	list(queue);

	printf("spool 5: ");
	spool(queue, 5);
	list(queue);	

	printf("spool 6: ");
	spool(queue, 6);
	list(queue);	

	printf("spool 7: ");
	spool(queue, 7);
	list(queue);

	printf("spool 8: ");
	spool(queue, 8);
	list(queue);
	
	printf("print: ");
	print(queue);
	list(queue);

	printf("print: ");
	print(queue);
	list(queue);

	printf("print: ");
	print(queue);
	list(queue);

	printf("print: ");
	print(queue);
	list(queue);

	printf("print: ");
	print(queue);
	list(queue);

	printf("print: ");
	print(queue);
	list(queue);


}

// Adds a job to the queue
void spool(Queue queue, int jobId) {
    enqueue(queue, jobId);
}

// Removes the job to be printed from the queue
int print(Queue queue) {
    return dequeue(queue);
}



// displays the queue
void list(Queue queue) {
    if(!queue || isEmpty(queue)) {
		printf("\n");
        return;
    }
    for(int i = 0; i < queue->numCount; i++) {
        printf("%d ", queue->nums[(queue->front+1+i)%queue->size]);
    }
    printf("\n");
}


/*
for(int i = queue->front+1; i != (queue->rear+1 )%queue->size; i = (i+1)%queue->size) {
        printf("%d ", queue->nums[i]);
    }
*/
