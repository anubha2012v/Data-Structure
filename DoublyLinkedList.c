#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

//Display function for displaying elements of a Doubly LinkedList.
void Display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p= p->next;
    }
    printf("\n")
}

//Creating LinkedList
void Create(int A[], int n){
    struct Node *t,*last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

//Fuunction for finding the length of A Doubly LL.
int Length(struct Node *p){
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    return len;
}

int main(){
    
    int A[] = {10,20,30,40,50};


    return 0;
}
