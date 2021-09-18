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


int main(){
    
    int A[] = {10,20,30,40,50};


    return 0;
}
