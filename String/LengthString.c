#include <stdio.h>

int main(){
    char A[] = "Anubhav Singh";
    int i;
    for(i=0; A[i] != '\0'; i++){}
    printf("%d \n", i);
    return 0;
}