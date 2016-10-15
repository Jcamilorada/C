#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
        int data;
        struct Node *next;
} node;

void insert(node *pointer, int data)
{
        while(pointer->next!=NULL)
        {
            pointer = pointer -> next;
        }

        pointer->next = (node *)malloc(sizeof(node));
        pointer = pointer->next;
        pointer->data = data;
        pointer->next = NULL;
}

int find(node *pointer, int key)
{
        pointer =  pointer -> next;
        while(pointer!=NULL)
        {
            if(pointer->data == key)
            {
                return 1;
            }
            pointer = pointer -> next;
        }
        return 0;
}

void delete(node *pointer, int data)
{
        while(pointer->next!=NULL && (pointer->next)->data != data)
        {
            pointer = pointer -> next;
        }
        if(pointer->next==NULL)
        {
            printf("Element %d is not present in the list\n",data);
            return;
        }

        node *temp;
        temp = pointer -> next;
        pointer->next = temp->next;
        free(temp);
        return;
}

void print(node *pointer)
{
        if(pointer==NULL)
        {
            return;
        }
        printf("%d ",pointer->data);
        print(pointer->next);
}