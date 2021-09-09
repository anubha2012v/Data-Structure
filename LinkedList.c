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

//Sum of all elements in a Linked List("Iterative Approach").
int Add(struct Node *p){
    int sum = 0;
    while (p != NULL){
        sum = sum + p->data;
        p= p->next;
    }
    return sum;
}

//Sum of all elements in a Linked List("Recursive Approach").
int RAdd(struct Node *p){
    if(p != NULL)
        return RAdd(p->next) + p->data;
    else
        return 0;
}

//Maximum Element in a linked list("Iterative Approach"). 
int Max(struct Node *p){
    int max = -65535;
    while (p != NULL){
        if (p->data > max) 
            max = p->data;
        p = p->next;
    }
    return max;
}

//Maximum Element in a linked list("Recursive Approach"). 
int RMax(struct Node *p){
    int x = 0;

    if(p == 0)
        return -65535;
    x = RMax(p->next);
    if(x > p->data)
        return x;
    else
        return p->data;
}

// Searching in Linked list Using Linear Search("Iterative Approach")
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Searching in Linked list Using Linear Search("Recursive Approach")
struct Node *RSearch(struct Node *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next, key);

}

//In this searching Key Value is moved to front
struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while (p != NULL)
    {
        if (key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p; 
        p = p->next;
    }
    return NULL;
}

//Inserting in a Linked List
void Insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Inserting at last(Specially if you want to insert new element at last)
void InsertLast(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

//Inserting Element in sorted order
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p != NULL && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}


int main()
{
//     int A[] = {3, 5, 7, 10, 25, 8, 12, 2};

//     create(A, 8);
    
//     printf("Elements in a linked list are: ");
//     Display(first);
//     printf("\nLength is: %d \n", Rcount(first));
//     printf("Sum of a Linked List is: %d \n", Add(first));
//     printf("Max is: %d \n",RMax(first));
    
//     temp = LSearch(first, 25);
//     temp = LSearch(first, 8);
    
//     if (temp != NULL)
//         printf("Key Found %d \n", temp->data);
//     else
//         printf("No Key Found");
//     Display(first);
    
//     Insert(first, 0, 10);
//     Insert(first, 1, 20);
//     Insert(first, 2, 30);
//     Insert(first, 0, 5);
    
    
//     InsertLast(10);
//     InsertLast(12);
//     InsertLast(14);
//     InsertLast(16);
//     InsertLast(18);
//     Display(first);
    
    SortedInsert(first,55);
    SortedInsert(first,25);

    Display(first);
    return 0;
}
