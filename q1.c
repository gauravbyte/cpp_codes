#include <stdio.h>

int main() {
    int arr[10];
    int i;
    int isNonDescending = 1;  // Assume it's non-descending initially
    for (i = 0; i < 10; i++) {
            scanf("%d", &arr[i]);
        
    }
    // Check if the array is non-descending
    for (i = 1; i < 10; i++) {
        if (arr[i] < arr[i-1]) {
            isNonDescending = 0;  // Found a descending order, set the flag to 0
            break;
        }
    }
    if (isNonDescending) {
        printf("The array is non-descending.\n");
    } else {
        printf("The array is not non-descending.\n");
    }

    return 0;
}