#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;


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

char isEmpty()
{
    return top ? 0 : 1;
}

char stackTop()
{
    if (top != NULL)
        return top->data;
    return -1;
}

int precedence(char x){
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else 
        return 1;
}

char * IntoPost(char *infix){
    int i = 0,j = 0;
    char *postfix;
    long len = strlen(infix);
    postfix = (char *)malloc((len+2)*sizeof(char));

    while (infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
            
        }
        
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int Evaluate(char *postfix){
    int i = 0;
    int x1,x2,r;

    for ( i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";

    printf("Result is: %d\n", Evaluate(postfix));

    return 0;
}

