//
// Created by ida on 16.11.20.
//

#include <stdio.h>
#include <stdlib.h>

void cut(double* x, int n, double cmin, double cmax) {
    int idx=0;
    for (int i=0; i < n; i++) {
        if (x[i] >= cmin && x[i] <= cmax) {
            x[idx] = x[i];
            idx++;
        }
    }
    x = realloc(x,idx);
}

int main() {
    double* arr;
    arr = malloc(8*sizeof(double));

    for (int i=0; i < 8; i++) {
        arr[i] = i * 2 - 3;
    }

    for (int i=0; i < 8; i++) {
        printf("%f, ",arr[i]);
    }
    printf("\n");

    cut(arr, 8, 0, 10);

    for (int i=0; i < 8; i++) {
        printf("%f, ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}