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

//Pop operation for Stack
int pop()
{
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty!\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

//find the element at given position
int peek(int pos){
    int i;
    struct Node *p = top;
    for(i = 0; p!=NULL && i< pos-1; i++)
        p = p->next;
    if(p != NULL)
        return p->data;
    else
        return -1;
}

//Finding top element of stack
int stackTop()
{
    if (top != NULL)
        return top->data;
    return -1;
}

//Checking whether the stack is empty
int isEmpty()
{
    return top ? 0 : 1;
}

//Checking whether the stack is full
int isFull()
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    int r = t ? 0 : 1;
    free(t);
    return r;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    Display();

    printf("%d ", peek(4));
    return 0;
}
