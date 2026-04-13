#include <stdio.h>
#include <string.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];
int m; // hash table size

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int index, i = 0;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash Table Overflow\n");
}

// Search using quadratic probing
int search(int key) {
    int index, i = 0;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == EMPTY)
            return 0;

        if (table[index] == key)
            return 1;

        i++;
    }

    return 0;
}

int main() {
    int n;
    char op[10];
    int key;

    // Initialize table
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;

    scanf("%d", &m); // table size
    scanf("%d", &n); // number of operations

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}