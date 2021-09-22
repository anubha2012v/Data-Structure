#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
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

char pop()
{
    struct Node *t;
    char x = -1;
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

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
        return 0;
    return 1;
}

int out_precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
}

int in_precedence(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
}

char * IntoPostfix(char *infix){
    int i = 0,j = 0;
    char *postfix;
    long len = strlen(infix);
    postfix = (char *)malloc((len+1)*sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            //As if stack is empty in_precedence of -1 (stacktop()) will give random result it is better to handle it
            if (isEmpty() || out_precedence(infix[i]) > in_precedence(stackTop()))
                push(infix[i++]);
            else if (in_precedence(stackTop()) > out_precedence(infix[i]))
                postfix[j++] = pop();
            else if (in_precedence(stackTop()) == out_precedence(infix[i])){
                pop();
                i++;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
    
}

int main()
{
    char *infix = "((a+b)*c)-d^e^f";

    char *postfix = IntoPostfix(infix);

    printf("%s ",postfix);
    return 0;
}

