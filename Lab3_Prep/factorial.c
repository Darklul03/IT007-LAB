// University of Information Technology
// Huynh Pham Duc Lam, 21521050
// File: factorial.c

#include <stdio.h>

int main() {
    int i, num, j=1;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
        j *= i;
    
    printf("The factorial of %d is %d\n", num, j);
    return 0;
}