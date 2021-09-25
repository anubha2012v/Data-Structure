#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "Anubhav";
    char t; //temp character
    int i, j;

    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    printf("%s \n", A);
    return 0;
}
