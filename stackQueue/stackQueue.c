/*************************************************************************
	> File Name: stackQueue.c
	> Author: Moby
	> Mail: 9712579@gmail.com
	> Created Time: Sun 27 Dec 2015 03:54:14 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct Queue;
typedef struct {
    Queue *head;
    Queue *tail;
    
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    Queue *top = queue;
    for(int i = 0; i < maxSize; i++)
    {
        Queue newQueue = (Queue*)malloc(sizeof(Queue));
        printf("new queue: %p, top: %p, top->tail: %p, top->head: %p\n", 
              newQueue, top, top->tail, top->head);
        top->tail = newQueue;
        top->head = top; 
        top = top->tail;
    }
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {


}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {


}

/* Get the front element */
int queuePeek(Queue *queue) {


}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {


}

/* Destroy the queue */
void queueDestroy(Queue *queue) {


}

int main(int argc, char **argv)
{
    Queue queueStack = NULL;
    int iSize = 5;
    queueCreate(queueStack, iSize);

    Queue printStack = queueStack;
    while(printStack->head == NULL)
    {
        printf("printStack->head: %p, tail: %p\n",
              printStack->head, printStack->tail);
        Queue pop = printStack->tail; 
        printf("pop: %p\n", pop);
        printStack->tail = NULL;
        printStack= printStack->head;
        printf("printStack head: %p, printStack: %p\n", printStack->head, printStack);
    }
}
