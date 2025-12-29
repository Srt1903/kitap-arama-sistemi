#ifndef QUEUE_H
#define QUEUE_H


#define QUEUE_SIZE 100


typedef struct {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;


/* Queue temel işlemleri */
void initQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);


#endif