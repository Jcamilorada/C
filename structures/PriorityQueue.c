#include <stdio.h>
#include <stdlib.h>

struct requirement 
{
    char* name;
    char* description;
    int priority;
};

struct nodeBase 
{
    struct requirement* req;
    struct nodeBase* next;
};

struct queueBase
{
    struct nodeBase* head;
    struct nodeBase* tail;
};

typedef struct requirement Requirement;
typedef struct queueBase Queue;
typedef struct nodeBase Nodo;

void enqueue(Queue* queue, Requirement* newReq)
{
    Nodo* newNodo = (Nodo*) malloc (sizeof(Nodo));
    newNodo->req = newReq;
    newNodo->next = NULL;

    if (queue->head == NULL)
    {
        queue->head = newNodo;
        queue->tail = newNodo;
    }

    else if (newReq->priority < queue->head->req->priority)
    {
        newNodo->next = queue->head;
        queue->head = newNodo;
    }

    else if (newReq->priority > queue->tail->req->priority)
    {
        Nodo* tmp = queue->tail;
        queue->tail = newNodo;
        tmp->next = newNodo;
    }

    else
    {
        Nodo* current = queue->head;

        while(current->next->req->priority < newReq->priority)
        {
            current = current->next;
        }

        newNodo->next = current->next;
        current->next = newNodo;
    }
}

Requirement dequeue(Queue* queue)
{
    Requirement* ans = queue->head->req;
    Nodo* tmp = queue->head;
    queue->head = tmp->next;

    free(tmp);
    return *ans;
}

void print(Queue* queue)
{
    Nodo* nodo = queue->head;
    while (nodo != NULL)
    {
        Requirement* req = nodo->req;
        printf("%s - %s - %d\n", req->name, req->description, req->priority);
        nodo = nodo->next;
    }
}

int main()
{
    Requirement* req1 = (Requirement*) malloc(sizeof(Requirement));
    req1->priority = 1;
    req1->name = "n1";
    req1->description = "d1";

    Requirement* req2 = (Requirement*) malloc(sizeof(Requirement));
    req2->priority = 2;
    req2->name = "n2";
    req2->description = "d2";

    Requirement* req3 = (Requirement*) malloc(sizeof(Requirement));
    req3->priority = 3;
    req3->name = "n3";
    req3->description = "d3";

    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, req2);
    enqueue(queue, req1);
    enqueue(queue, req3);
    print(queue);

    printf("\n");
    dequeue(queue);
    print(queue);

    return 1;
}