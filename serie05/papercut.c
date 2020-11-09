//
// Created by ida on 09.11.20.
//

#include <stdio.h>
#include <stdlib.h>

int* prefix;

void papercut(int n) {
    //printf("Called with n=%d\n", n);
    if (n <= 0) {
        int i = 0;
        while (prefix[i] != 0) {
            printf("%d ", prefix[i]);
            i++;
        }
        printf("\n");
        return;
    }
    /* Set next value in prefix to 1 and the next one to 0. */
    int i = 0;
    while (prefix[i] != 0) {
        i++;
    }
    prefix[i] = 1;
    prefix[i+1] = 0;
    /* Call recursion. */
    papercut(n-1);

    if (n >= 2) {
        /* Change last value in prefix to 2. */
        if (prefix[0] == 0) {
            return;
        }
        i = 0;
        while (prefix[i + 1] != 0) {
            i++;
        }
        prefix[i] = 2;
        /* Call recursion. */
        papercut(n - 2);
    }
    /* Delete last value in prefix. */
    if (prefix[0] == 0) {
        return;
    }
    i = 0;
    while (prefix[i+1] != 0) {
        i++;
    }
    prefix[i] = 0;
}

int main() {
    printf("Prints all possibilities to sum n with the numbers 1 and 2.\n");

    int n = 0;

    printf("Please enter a number for n=");
    scanf("%d", &n);

    prefix = (int*) malloc(n * sizeof(int));
    prefix[0] = 0;

    papercut(n);

    return 0;
}