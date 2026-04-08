/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        // Stack overflow (not required in problem but safe)
        return;
    }
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        // Stack underflow (not required in problem but safe)
        return;
    }
    top--;
}

// Display function (top to bottom)
void display() {
    if (top == -1) {
        printf("Stack is empty");
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0)
            printf(" ");
    }
}

int main() {
    int n, m, x;

    // Input number of elements
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}