/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Pop operation
struct Node* pop(struct Node* top, int* value) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    struct Node* temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* top = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (digit)
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            top = push(top, num);
        }
        else {
            int val1, val2;

            // Pop two operands
            top = pop(top, &val2);
            top = pop(top, &val1);

            int result;

            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            top = push(top, result);
            i++;
        }
    }

    int finalResult;
    top = pop(top, &finalResult);
    return finalResult;
}

// Main function
int main() {
    char exp[100];

    // Read full line including spaces
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}