#include <stdio.h>

int main() {
    int size, pos;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }
    
    int arr[size];
    
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the position to delete (1 to %d): ", size);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > size) {
        printf("Invalid position.\n");
        return 1;
    }
    
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    size--;
    
    printf("Array after deletion:\n");
    if (size == 0) {
        printf("The array is empty.\n");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}