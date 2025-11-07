#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];    // Array to store elements
int top[10];     // Top of each stack (supports up to 10 stacks)
int next[MAX];   // Next free or next element in stack
int freeIndex;   // Points to the beginning of free list
int nStacks;     // Number of stacks

// Initialize N stacks
void initialize(int n) {
    nStacks = n;

    for (int i = 0; i < n; i++)
        top[i] = -1; // Initialize all stacks as empty

    for (int i = 0; i < MAX - 1; i++)
        next[i] = i + 1;
    next[MAX - 1] = -1; // -1 indicates end of free list

    freeIndex = 0; // First free slot
}

// Push operation
void push(int stackNum, int value) {
    if (freeIndex == -1) {
        printf("Stack Overflow!\n");
        return;
    }

    int i = freeIndex;        // Get free index
    freeIndex = next[i];      // Update free list
    next[i] = top[stackNum];  // Link new element to previous top
    top[stackNum] = i;        // Update top pointer
    arr[i] = value;           // Store value

    printf("%d pushed to Stack %d\n", value, stackNum + 1);
}

// Pop operation
void pop(int stackNum) {
    if (top[stackNum] == -1) {
        printf("Stack %d Underflow!\n", stackNum + 1);
        return;
    }

    int i = top[stackNum];      // Index to pop
    top[stackNum] = next[i];    // Update top to next element
    next[i] = freeIndex;        // Add this index back to free list
    freeIndex = i;              // Update freeIndex

    printf("%d popped from Stack %d\n", arr[i], stackNum + 1);
}

// Display all stacks
void display
