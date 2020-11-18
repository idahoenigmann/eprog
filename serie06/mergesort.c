//
// Created by ida on 17.11.20.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* merge(double* x, double* y, int len_x, int len_y) {
    double* res = malloc(sizeof(double)*(len_x+len_y));

    int idx_x = 0;
    int idx_y = 0;
    int idx_res = 0;

    while (idx_x < len_x || idx_y < len_y) {
        if (x[idx_x] < y[idx_y] && idx_x < len_x) {
            res[idx_res] = x[idx_x];
            idx_x++;
        } else {
            res[idx_res] = y[idx_y];
            idx_y++;
        }
        idx_res++;
    }

    free(x);
    free(y);
    return res;
}

void mergeSort(double* x, int n) {
    if (n == 1) {
        return;
    } else if (n == 2) {
        if (x[0] > x[1]) {
            double tmp = x[1];
            x[1] = x[0];
            x[0] = tmp;
        }
        return;
    }
    int len_x = (int)(n/2.0);



    mergeSort(x,len_x);
    mergeSort(x+len_x,n-len_x);
    double* merged = merge(x,x+len_x,len_x,n-len_x);
    for (int i=0; i < n; i++) {
        x[i] = merged[i];
    }
}

int main() {
    printf("Sorts a given vector using merge sort.\n");

    int n = 0;
    double* arr;

    printf("Please enter a value for the length of the vector: ");
    scanf("%d", &n);

    arr = malloc(n*sizeof(double));

    for(int i=0; i < n; i++) {
        printf("Please enter a value for x[%d]= ",i);
        scanf("%lf", arr+i);
    }

    printf("Unsorted vector:\n");
    for(int i=0; i < n; i++) {
        printf("%f, ", arr[i]);
    }

    mergeSort(arr, n);

    printf("\nSorted vector:\n");
    for(int i=0; i < n; i++) {
        printf("%f, ", arr[i]);
    }

    printf("\n");
    free(arr);
    return 0;
}