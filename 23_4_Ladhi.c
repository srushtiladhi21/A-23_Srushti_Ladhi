#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void enqueue1(int value) {
    if (rear1 + 1 == rear2) {
        printf("Queue Overflow!\n");
    } else {
        if (front1 == -1) front1 = 0;
        arr[++rear1] = value;
        printf("%d enqueued to Queue 1\n", value);
    }
}

void enqueue2(int value) {
    if (rear2 - 1 == rear1) {
        printf("Queue Overflow!\n");
    } else {
        if (front2 == MAX) front2 = MAX - 1;
        arr[--rear2] = value;
        printf("%d enqueued to Queue 2\n", value);
    }
}

1
void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue 1 Underflow!\n");
    } else {
        printf("%d dequeued from Queue 1\n", arr[front1++]);
        if (front1 > rear1) front1 = rear1 = -1;
    }
}

void dequeue2() {
    if (front2 == MAX || front2 < rear2) {
        printf("Queue 2 Underflow!\n");
    } else {
        printf("%d dequeued from Queue 2\n", arr[front2--]);
        if (front2 < rear2) front2 = rear2 = MAX;
    }
}

void display() {
    printf("\nQueue 1: ");
    if (front1 == -1)
        printf("Empty");
    else
        for (int i = front1; i <= rear1; i++) printf("%d ", arr[i]);

    printf("\nQueue 2: ");
    if (front2 == MAX)
        printf("Empty");
    else
        for (int i = front2; i >= rear2; i--) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Two Queues Using Single Array ---\n");
        printf("1. Enqueue in Queue 1\n2. Dequeue from Queue 1\n");
        printf("3. Enqueue in Queue 2\n4. Dequeue from Queue 2\n");
        printf("5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue1(value);
                break;
            case 2:
                dequeue1();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue2(value);
                break;
            case 4:
                dequeue2();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
