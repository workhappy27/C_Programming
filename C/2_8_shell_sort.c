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
//            for(j=i-1; j>=0 && arr[j] > key; j--) {
              printf("key: %d ", key);
              for(j=i; (j>=gap && arr[j-gap] > key); j = j-gap) {
                arr[j] = arr[j-gap];            //arr[] = arr[]
                printf("i=%d j=%d j-gap: %d ::", i, j, j-gap);
                for (k=0; k<n; k++)
                    printf("%d ", arr[k]);
                printf("\n");
            }
            arr[j] = key;                     // arr[] = key
            printf("\n");
            for (k=0; k<n; k++)
                printf("%d ", arr[k]);
            printf("\n");
    }

    }
    printf("Sorted array: ");
    for (k=0; k<n; k++)
        printf("%d ", arr[k]);
    printf("\n");
}
/* Output:
The inner for loop condition (j >= gap && arr[j - gap] > key) compares elements
that are gap apart and shifts them forward by gap.
n: 6
Sort array: 7 3 1 44 35 8
gap: 3 key: 44
7 3 1 44 35 8
key: 35
7 3 1 44 35 8
key: 8
7 3 1 44 35 8

gap: 1 key: 3 i=1 j=1 j-gap: 0 ::7 7 1 44 35 8
3 7 1 44 35 8

key: 1 i=2 j=2 j-gap: 1 ::3 7 7 44 35 8
i=2 j=1 j-gap: 0 ::3 3 7 44 35 8

1 3 7 44 35 8
key: 44
1 3 7 44 35 8
key: 35 i=4 j=4 j-gap: 3 ::1 3 7 44 44 8

1 3 7 35 44 8
key: 8 i=5 j=5 j-gap: 4 ::1 3 7 35 44 44
i=5 j=4 j-gap: 3 ::1 3 7 35 35 44

1 3 7 8 35 44
Sorted array: 1 3 7 8 35 44
*/
