#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* right;
    struct node* left;
    int value;
};

typedef struct node Node;

void insert(Node** node, int value)
{
    if (*node == NULL)
    {
        Node* new = (Node*) malloc(sizeof(Node));
        new->right = NULL;
        new->left = NULL;
        new->value = value;
        *node = new;
    }

    else
    {
        Node* currentNode = *node;

        if (value > currentNode->value)
        {
            insert(&(currentNode->right), value);
        }

        else
        {
             insert(&(currentNode->left), value);
        }
    }
}

void printTree(Node* node)
{
    if (node != NULL)
    {
        printf("%d", node->value);
        printTree(node->left);
        printTree(node->right);
    }
}

int main()
{
    Node * tree;
    insert(&tree, 5);
    insert(&tree, 6);
    insert(&tree, 3);
    insert(&tree, 8);
    printTree(tree);
}