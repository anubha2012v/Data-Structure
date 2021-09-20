#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

//Display function
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//Push Operation for Stack
void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Stack is full!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}



int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    Display();

    printf("%d ", isFull());
    return 0;
}
