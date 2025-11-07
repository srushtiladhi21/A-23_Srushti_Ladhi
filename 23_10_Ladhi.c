#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(rear == NULL) front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", front->data);
    front = front->next;
    if(front == NULL) rear = NULL;
}

void display() {
    struct Node* temp = front;
    if(temp == NULL) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
