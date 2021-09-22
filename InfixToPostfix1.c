#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int Top;
    char *s;
};

void push(struct Stack *st, char x)
{
    if (st->Top == st->size - 1)
        printf("Stack Overflow....");
    else
    {
        st->Top++;
        st->s[st->Top] = x;
    }
}

char pop(struct Stack *st)
{
    char x = '0';
    if (st->Top == -1)
        printf("Stack underflow");

    else
    {
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.Top == -1)
        return 1;
    return 0;
}

char stackTop(struct Stack st)
{
    if (st.Top == -1)
        return -1;
    else
        return st.s[st.Top];
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
        return 0;
    return 1;
}

int out_prece(char x)
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

int in_prece(char x)
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

char *Convert(char *Infix)
{
    struct Stack st;
    st.size = strlen(Infix);
    st.Top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    char *Postfix = (char *)malloc((strlen(Infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (Infix[i] != '\0')
    {
        if (isOperand(Infix[i]))
            Postfix[j++] = Infix[i++];
        else
        {
            if (out_prece(Infix[i]) > in_prece(stackTop(st)))
                push(&st, Infix[i++]);
            else if (in_prece(stackTop(st)) > out_prece(Infix[i]))
                Postfix[j++] = pop(&st);
            else if (in_prece(stackTop(st)) == out_prece(Infix[i])){
                pop(&st);
                i++;
            }
        }
    }
    while (!isEmpty(st))
    {
        Postfix[j++] = pop(&st);
    }
    Postfix[j] = '\0';
    return Postfix;
}

int main()
{
    char *Infix = "((a+b)*c)-d^e^f";
    printf("((a+b)*c)-d^e^f  \n");

    printf("PostFix Form is : ");
    char *Postfix = Convert(Infix);

    printf("%s ", Postfix);
}