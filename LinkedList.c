#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

//Method for Displaying Linked List
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

//Recursive method for displaying linked list
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

//Display Linked List in reverse order
void Rdisplay(struct Node *p){
    if (p != NULL)
    {
        Rdisplay(p->next);
        printf("%d ", p->data);
    }
    
}

//Method for creating Linked List 
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//Counting nodes in a Linked List("Iterative Approach").
int count(struct Node *p){
    int c = 0;
    while (p!= NULL)
    {
        c++;
        p= p->next;
    }
    return c;
}

//Counting nodes in a Linked List("Recursive Approach").
int Rcount(struct Node *p){
    if( p!= NULL ) 
        return count(p->next) + 1;
    else
        return 0;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);

    // Display(first);
    printf("Length is: %d ", Rcount(first));
    return 0;
}