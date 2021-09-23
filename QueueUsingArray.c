#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front; // front pointer for deletion
    int rear; // rear pointer for insertion
    int *Q;
};

void enqueue(struct Queue *q,int x){
    if(q->rear == q->size-1)
        printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    if(q.front == q.rear)
        return 1;
    return 0;
}

int isFull(struct Queue q){
    if(q.rear == q.size-1)
        return 1;
    return 0;
}

void createQueue(struct Queue *q,int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *) malloc(q->size * sizeof(int));
}

void Display(struct Queue q){
    int i;
    for(i=q.front+1; i<=q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int first(struct Queue q){
    if(isEmpty(q)) //changes
        return -1;
    else
        return q.Q[q.front+1]; //changes
}

int last(struct Queue q){
    if(isEmpty(q))//changes
        return -1;
    else
        return q.Q[q.rear]; //changes
}

int main(){
    struct Queue q;
    createQueue(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    // Display(q);

    // printf("%d ",dequeue(&q));
    // printf("\n");
    // printf("%d ",dequeue(&q));
    // printf("\n");
    // printf("%d ",dequeue(&q));
    // printf("\n");
    // printf("%d ",dequeue(&q));
    // printf("\n");
    // printf("%d ",isEmpty(q));

    Display(q);
    printf("\n");
    printf("%d \n", first(q));

    return 0;
}