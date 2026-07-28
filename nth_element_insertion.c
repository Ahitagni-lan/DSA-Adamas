#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size, pos, value;
    
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size < 0 || size > MAX_SIZE) {
        printf("Error: Invalid array size.\n");
        return 1;
    }
    
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (size == MAX_SIZE) {
        printf("Error: Array is full. Cannot insert.\n");
        return 1;
    }
    
    printf("Enter the position to insert (1 to %d): ", size + 1);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > size + 1) {
        printf("Error: Invalid position.\n");
        return 1;
    }
    
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = value;
    size++;
    
    printf("\nArray after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}