#include 
#include 

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtNth(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int value, pos;

    while (1) {
        printf("Enter value (-1 to stop): ");
        scanf("%d", &value);
        if (value == -1) break;

        printf("Enter position: ");
        scanf("%d", &pos);

        head = insertAtNth(head, value, pos);
        display(head);
    }

    return 0;
}
