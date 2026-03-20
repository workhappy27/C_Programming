#include<stdio.h>
#include<stdlib.h>

void main()
{
int arr[] = {7,3,1,44,35,8};
int i, j, n, key, k;
int gap=0;

    n = sizeof(arr) / sizeof(arr[0]);

    printf("n: %d\n", n);
    printf("Sort array: ");
    for (k=0; k<n; k++)
        printf("%d ", arr[k]);
    printf("\n");

    for(gap=n/2; gap>0; gap = gap/2) {
        printf("gap: %d ", gap);
        for(i=gap; i<n; i++) {
            key = arr[i];                         //key = arr[3]
            for(j=i-1; j>=0 && arr[j] > key; j--) {
                arr[j+1] = arr[j];            //arr[] = arr[]
                printf("i=%d, ", i);
                for (k=0; k<n; k++)
                    printf("%d ", arr[k]);
                printf("\n");
            }
            arr[j+1] = key;                     // arr[] = key
    }

    }
    printf("Sorted array: ");
    for (k=0; k<n; k++)
        printf("%d ", arr[k]);
    printf("\n");
}

/* Output:
n: 6
Sort array: 7 3 1 44 35 8
gap: 3 i=4, 7 3 1 44 44 8
i=5, 7 3 1 35 44 44
i=5, 7 3 1 35 35 44
gap: 1 i=1, 7 7 1 8 35 44
i=2, 3 7 7 8 35 44
i=2, 3 3 7 8 35 44
Sorted array: 1 3 7 8 35 44
