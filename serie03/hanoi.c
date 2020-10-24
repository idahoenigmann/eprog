//
// Created by ida on 24.10.20.
//

#include <stdio.h>

void hanoi(int m, int i, int j) {
    if (m == 0) {
        return;
    }

    // find auxiliary rode
    int k = 1;
    for (int l=1; l <= 3; l++) {
        if (i != l && j != l) {
            k = l;
            break;
        }
    }

    hanoi(m - 1, i, k);
    printf("Move a disk from Rode %d to Rode %d.\n", i, j);
    hanoi(m - 1, k, j);
}

int main() {
    printf("Solve tower of hanoi problem for n disks.\n");

    int n = 0;
    printf("Please enter a value for n: ");
    scanf("%d", &n);

    hanoi(n, 1, 3);
    return 0;
}