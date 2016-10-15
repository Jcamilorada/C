#include<stdio.h>
#include<stdlib.h>

struct ArrayListBase 
{
    int capacity;
    int sizeOfData;
    int increment;
    int* basicArray;
};

typedef struct ArrayListBase ArrayList;

ArrayList* initiallise ()
{
    ArrayList *list = malloc(sizeof(ArrayList));
    list->capacity = 10;
    list->sizeOfData = 0;
    list->increment = 10;
    list->basicArray = calloc(10, sizeof(int));
    
    return list;
}
void insert(ArrayList *pointer, int data)
{
    if((pointer->sizeOfData + 1) > pointer->capacity)
    {
        pointer->basicArray =
            realloc(
                pointer->basicArray,
                (pointer->capacity + pointer->increment)*sizeof(int));
        pointer->capacity += pointer->increment;
    }
    
    pointer->sizeOfData++;
    pointer->basicArray[pointer->sizeOfData - 1] = data;
}

void delete(ArrayList *pointer, int value)
{
    int i = 0;
    for(i = 0; i<pointer->sizeOfData; i++)
    {
        if(pointer->basicArray[i] == value)
            break;
    }

    if(i < pointer->sizeOfData)
    {
        pointer->sizeOfData--;

        memmove(pointer->basicArray + i, pointer->basicArray + i + 1, (pointer->sizeOfData - i)*sizeof(int));
        if(pointer->sizeOfData <= (pointer->capacity - pointer->increment))
        {
            pointer->capacity -= pointer->increment;
            pointer->basicArray = realloc(pointer->basicArray, pointer->capacity*sizeof(int));
        }
    }
}

int elementAt(ArrayList *pointer, int index)
{
    if (index >= 0 && index < pointer->sizeOfData)
    {
        return pointer->basicArray[index];
    }
    
    return NULL;
}

int main()
{
    int i=0;
    ArrayList *list = initiallise();

    for(i = 0; i< 30; i++)
    {
        insert(list, i);
    }
    
        delete(list, 10);

    for(i = 0; i< list->sizeOfData; i++)
    {
        printf("list[%i] = %i\n", i, list->basicArray[i]);
    }
    
    printf("capacity = %d", list->capacity);
}