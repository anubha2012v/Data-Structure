#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

//creating linked list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

//Method for displaying Linked List
void Display(struct Node *h){
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n"); 
}

//Recursive Display Method
void RDisplay(struct Node *h){
    static int flag = 0;
    if(h!=head || flag==0){
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

//Length of the circular linked list
int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}



int main()
{

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Display(head);
    return 0;
}
