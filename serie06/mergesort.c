//
// Created by ida on 17.11.20.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(double* x, int n) {

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