#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node * next;
};
typedef struct node Node;

struct queue
{
    Node * head;
    Node * tail;
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

void print(Queue *myQueue)
{
    Node * tmpNode = myQueue->head;
    while(1)
    {
        if(tmpNode == NULL)
        {
            break;
        }
        else
        {
            printf("%i\n", tmpNode->value);
            tmpNode = tmpNode->next;
        }
    }
}

int main()
{
    Queue * myQueue = (Queue*)malloc(sizeof(Queue));
    myQueue->head = NULL;
    myQueue->tail = NULL;
    
    enqueue(myQueue, 5);
    enqueue(myQueue, 15);
    enqueue(myQueue, 25);
    enqueue(myQueue, 35);
    dequeue(myQueue);
    
    print(myQueue);
}
