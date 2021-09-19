#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last, *second = NULL, *third = NULL;

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

//Method for creating another linked list
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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

//Deleting Elements at any index
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

//To check if the Element of a linked list is sorted or not.
int isSorted(struct Node *p)
{
    int x = -65535;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

//Removing Duplicate Elements from Linked List.
void RemoveDuplicate(struct Node *p){
    struct Node *q = p->next;
    while (q != NULL){
        if(p->data != q->data){
            p = q; 
            q = q->next;
        }else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
} 

//Reversing in linked list
void Reverse1(struct Node *p){
    int *A, i=0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int)* count(p));

    while(q!=NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL){
        q->data = A[i];
        q = q->next;
        i--;
    }
}

//Reversing the linked list by Using Sliding(3 pointers) pointers.
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

//Reversing the linked list (#Recursively)
void Reverse3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

//Concating two linked lists
void Concat(struct Node *p, struct Node *q){
    third = p;

    while(p->next != NULL)
        p = p->next;
    p->next = q;
}

//Merge Two Linked Lists.
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    if (q != NULL)
        last->next = q;
}

//Finding Middle Element in a Linked List
void Middle(struct Node *p){
    int length = 0;
    struct Node* q = first;
    while (p != NULL){
        length++;
        p = p->next;
    }

    //Here we are taking (Ceil function) don't forget to include (#include <math.h>)
    int index = (int)ceil(length/2.0);
    for (int i=0; i<index-1; i++){
        q = q->next;
    }
    printf("Middle Element (Method-I):  %d", q->data);
}

//Another Method for finding the middle element of a Linked List
void Middle1(struct Node* p){
    struct Node* q = p;
    while (q != NULL){
        q = q->next;
        if (q){
            q = q->next;
        }
        if (q){
            p = p->next;
        }
    }
    printf("Middle Element (Method-II):  %d", p->data);  
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
    
//     SortedInsert(first,55);
//     SortedInsert(first,25);

//     Display(first);
    
//     int A[] = {10, 20, 30, 40, 50};
//     create(A, 5);

//     Delete(first,4);

//     Display(first);
    
 
// int A[] = {10, 2, 30, 40, 50};
//     create(A, 5);

//     if (isSorted(first))
//     {
//         printf("Sorted.\n");
//     }
//     else
//     {
//         printf("Not Sorted.\n");
//     }

//     int A[] = {10, 20, 20, 30, 30, 40, 50};
//     create(A, 7);
    
//     RemoveDuplicate(first);
//     Display(first);

//     int A[] = {10, 20, 30, 40, 50};
//     create(A, 5);
    
//     Reverse3(NULL,first);
//     Display(first);

//     int A[] = {50,40,10,30,20};
//     int B[] = {1,2,3,4,5};

//     create(A, 5);
//     create2(B,5);

//     Concat(first, second);
//     Display(third);
    
//     int A[] = {10,20,30,40,50};
//     int B[] = {5,15,25,35,45};
//     create(A, 5);
//     create2(B,5);

//     Merge(first, second);
//     Display(third);
    
    
    
    return 0;
}
