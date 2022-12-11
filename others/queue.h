typedef struct queue* Queue;
struct queue {
    int* nums;
    int front;
    int rear;
    int size;
    int numCount;
};

Queue makeNewQueue(int size);
void enqueue(Queue queue ,int item);
int dequeue(Queue queue);
int isFull(Queue queue);
int isEmpty(Queue queue);

// Makes a new queue
Queue makeNewQueue(int size) {
    int* arr = (int*)malloc(size*sizeof(int));
    Queue newQueue = (Queue)malloc(sizeof(struct queue));
    newQueue->nums = arr;
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = size;
    newQueue->numCount = 0;
    return newQueue;
}

// Checks if the queue is full
int isFull(Queue queue) {
    return (queue->size == queue->numCount);
}

// Checks if the queue is empty
int isEmpty(Queue queue) {
    return queue->numCount==0;
}


// Puts the item at the end of the queue
void enqueue(Queue queue, int item) {
    if(!queue || isFull(queue)) {
        return;
    } 
    queue->rear = (queue->rear + 1) % queue->size;
    queue->nums[queue->rear] = item;
    queue->numCount++;
}

// Removes the item from the first of the queue
int dequeue(Queue queue) {
    if(!queue || isEmpty(queue)) {
        return -1;
    }

    queue->front = (queue->front + 1) % queue->size;
    queue->numCount--;
    return queue->nums[queue->front];
}

// Returns the item at the front
int getFront(Queue queue) {
    if(!queue || isEmpty(queue)) {
        return -1;
    }
    return queue->nums[queue->front+1];
}

// Returns the item at the rear
int getRear(Queue queue) {
    if(!queue || isEmpty(queue)) {
        return -1;
    }
    return queue->nums[queue->rear];
}
