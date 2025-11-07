#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool endOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = malloc(sizeof(struct TrieNode));
    node->endOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    curr->endOfWord = true;
}

bool search(struct TrieNode* root, const char* word) {
    struct TrieNode* curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!curr->children[index]) return false;
        curr = curr->children[index];
    }
    return curr->endOfWord;
}

int main() {
    struct TrieNode* root = createNode();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "hi");

    printf(search(root, "hello") ? "Found\n" : "Not Found\n");
    printf(search(root, "hero") ? "Found\n" : "Not Found\n");
    return 0;
}
