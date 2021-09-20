#include <stdio.h>
#include <stdlib.h>


int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    Display();

    printf("%d ", isFull());
    return 0;
}
