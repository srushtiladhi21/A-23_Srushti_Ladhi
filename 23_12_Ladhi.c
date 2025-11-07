#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) { *head = newNode; return; }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp && temp->data == key) { *head = temp->next; free(temp); return; }
    while (temp && temp->data != key) { prev = temp; temp = temp->next; }
    if (!temp) return;
    prev->next = temp->next;
    free(temp);
}

void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void middle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle Element: %d\n", slow->data);
}

void sort(struct Node* head) {
    struct Node *i, *j;
    for (i = head; i; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int temp = i->data; i->data = j->data; j->data = temp;
            }
}

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int sum(struct Node* head) {
    int s = 0;
    while (head) { s += head->data; head = head->next; }
    return s;
}

void printOddEven(struct Node* head) {
    printf("Odd: ");
    struct Node* temp = head;
    while (temp) { if (temp->data % 2) printf("%d ", temp->data); temp = temp->next; }
    printf("\nEven: ");
    temp = head;
    while (temp) { if (temp->data % 2 == 0) printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

void display(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    insertEnd(&list1, 5); insertEnd(&list1, 2); insertEnd(&list1, 8);
    insertEnd(&list2, 3); insertEnd(&list2, 7);

    printf("List1: "); display(list1);
    printf("List2: "); display(list2);

    struct Node* merged = merge(list1, list2);
    printf("Merged: "); display(merged);

    sort(merged);
    printf("Sorted: "); display(merged);

    middle(merged);
    printf("Sum: %d\n", sum(merged));
    printOddEven(merged);

    reverse(&merged);
    printf("Reversed: "); display(merged);
    return 0;
}
