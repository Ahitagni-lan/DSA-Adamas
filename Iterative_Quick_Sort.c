#include <stdio.h>

int main() {
    int n;
    
    // 1. Take user input for array size and elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 2. Iterative Quick Sort Logic
    int stack[n]; 
    int top = -1;

    // Push initial values onto the stack
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        // Pop high and low
        int high = stack[top--];
        int low = stack[top--];

        // Partition Logic
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i + 1] and arr[high] (pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int p = i + 1; // The partition index

        // If there are elements on left side of pivot, push to stack
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot, push to stack
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }

    // 3. Print the sorted array
    printf("Sorted array (Quick Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}