#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* rotateArray(int n, int k, int* arr) {
    int* startSlice = malloc(k * sizeof(int));
    int* endSlice = malloc((n - k) * sizeof(int));
    
    memcpy(startSlice, &arr[n - k], k * sizeof(int));
    memcpy(endSlice, arr, (n - k) * sizeof(int));
    
    int* newArray = malloc(n * sizeof(int));
    memcpy(newArray, startSlice, k * sizeof(int));
    memcpy(&newArray[k], endSlice, (n - k) * sizeof(int));
    
    free(startSlice);
    free(endSlice);
    
    return newArray;
}

bool equalArrays(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int nosElement = 7;
    int steps = 3;
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int solution[] = {5, 6, 7, 1, 2, 3, 4};
    
    int* result = rotateArray(nosElement, steps, array);
    int resultSize = nosElement;
    
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    if (equalArrays(result, solution, resultSize)) {
        printf("Matched\n");
    } else {
        printf("Error in the Code\n");
    }
    
    free(result);
    
    return 0;
}
