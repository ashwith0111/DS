#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createCircularList(int arr[], int size) {
    if (size == 0) return;
    struct Node *newNode, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = head;
    last = head;
    for (int i = 1; i < size; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = head;
        last->next = newNode;
        last = newNode;
    }
}

void insertAtPosition(int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        int count = 1;
        struct Node* prev = NULL;
        while (temp->next != head && count < pos) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count == pos) {
            prev->next = newNode;
            newNode->next = temp;
        } else {
            printf("Invalid position.\n");
        }
    }
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;

    if (pos == 1) {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            head = head->next;
            last->next = head;
            free(temp);
        }
    } else {
        int count = 1;
        while (temp->next != head && count < pos) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count == pos) {
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Invalid position.\n");
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("DONE\n");
}

int main() {
    int size;
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    createCircularList(a, size);
    display();

    int  pos;
    char i;
    scanf("%d",&i);
    switch (i) {
        case 'i':
        int value;
            scanf("%d %d", &value, &pos);
            insertAtPosition(value, pos);
            break;
        case 'd':
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    display(); // To see the updated list after insertion or deletion
    return 0;
}
