#include <stdio.h>
#include "queue.h"


void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}


int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}


int isQueueFull(Queue *q) {
    return q->rear == QUEUE_SIZE;
}


void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue dolu! Ekleme yapilamadi.\n");
        return;
    }
    q->items[q->rear++] = value;
}


int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue bos! Cikarma yapilamadi.\n");
        return -1;
    }
    return q->items[q->front++];
}