#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    
    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enter data (Enqueue)\n");
        printf("2. Delete data (Dequeue)\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to add an element to the queue
void enqueue() {
    int value;
    
    // Check for Queue Overflow
    if (rear == MAX - 1) {
        printf("Error: Queue Overflow! The queue is full.\n");
        return;
    }
    
    printf("Enter data to insert: ");
    scanf("%d", &value);
    
    // If inserting the first element
    if (front == -1) {
        front = 0;
    }
    
    rear++;
    queue[rear] = value;
    printf("Successfully inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue
void dequeue() {
    // Check for Queue Underflow
    if (front == -1 || front > rear) {
        printf("Error: Queue Underflow! The queue is empty.\n");
        return;
    }
    
    printf("Deleted element: %d\n", queue[front]);
    front++;
    
    // Reset pointers if queue becomes empty after deletion
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Function to display all elements of the queue
void display() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
