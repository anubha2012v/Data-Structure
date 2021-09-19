#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

//Creating Stack
void Create(struct Stack *st)
{
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

//Display function for Stack
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

//Push function for inserting elements to stack
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow!\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

//Pop function for deleting elements from stack
int pop(struct Stack *st){
    int x = -1;
    if (st->top == -1)
        printf("Stack Unerflow!\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int main()
{
    struct Stack st;
    Create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));
    Display(st);
    return 0;
}