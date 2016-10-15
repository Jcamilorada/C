#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node * next;
};

typedef struct node Node;

void push(Node **myNode, int value)
{
    Node * newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *myNode;
    *myNode = newNode;
}

int pop(Node **myNode)
{
    if(*myNode == NULL)
    {
        printf("Error!\n");
        return;
    }
    Node *temp;
    int valueToReturn;

    temp = *myNode;
    valueToReturn = (*myNode)->value;
    *myNode = (*myNode)-> next;
    free(temp);
    return valueToReturn;
}

void print (Node *myNode)
{
    while(1)
    {
        if(myNode != NULL)
        {
            printf("%i\n", myNode->value);
            myNode = myNode->next;
        }
        else
        {
            break;
        }
    }
}


int main()
{
    Node * stack = NULL;
    pop(&stack);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 20);
    print(stack); 
    printf("%d\n", pop(&stack));
    print(stack);
}