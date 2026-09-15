#include 
#include 

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteAfterNode(struct Node* head, int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after target or target not found!\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
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
    int n, val, target;
    printf("Enter number of initial elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        head = insertAtEnd(head, val);
    }
    printf("Original ");
    display(head);
    printf("Enter target node value to delete after: ");
    scanf("%d", &target);
    head = deleteAfterNode(head, target);
    printf("After deletion: ");
    display(head);
    return 0;
}
