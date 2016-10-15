#include <stdio.h>
#include <stdlib.h>

struct queue
{
    Node * head;
    Node * tail;
};

struct queue
{
    Node * head;
    Node * tail;
    
    void (*enqueue)(struct queue *, int);
    int (*dequeue)(struct queue *);
    void (*print)(struct queue *);
};

typedef struct queue Queue;


void enqueue (Queue *myQueue, int element)
{
    Node * myNode = (Node*)malloc(sizeof(Node));
    myNode->value = element;
    myNode->next = NULL;

    Node * tmpNode = myQueue->head;
    
    if (tmpNode == NULL)
    {
        tmpNode = myNode;
        myQueue->head = myNode;
        myQueue->tail = myNode;
    }
    else
    {
        (myQueue)->tail->next = myNode;
        (myQueue)->tail = myNode; 
    }
}

int dequeue (Queue *myQueue)
{
    int value = 0;

    if (myQueue->head == NULL)
    {
        value = NULL;
    }
    else
    {
        Node * tmpNode = myQueue->head;
        value = tmpNode->value;
        myQueue->head = tmpNode->next;
        free(tmpNode);
    }
    return value;
}

Queue * constructor()
{
    Queue * myQueue = (Queue*)malloc(sizeof(Queue));
    myQueue->enqueue = enqueue;
    myQueue->dequeue = dequeue;
    myQueue->print = print;
    return myQueue;
}


int main()
{
    Queue * myQueue = constructor();
    myQueue->enqueue(myQueue, 5);
}