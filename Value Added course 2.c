#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100000 // Based on the constraint 10^5

// Stack structure
char stack[MAX];
int top = -1;

// Push element onto stack
void push(char c) {
    stack[++top] = c;
}

// Pop element from stack
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// Function to check if brackets are balanced
bool isBalanced(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];

        // If it's an opening bracket, push to stack
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        } 
        // If it's a closing bracket
        else {
            // Stack cannot be empty when a closing bracket appears
            if (top == -1) return false;

            char lastOpened = pop();

            // Check if the closing bracket matches the last opened one
            if ((current == ')' && lastOpened != '(') ||
                (current == '}' && lastOpened != '{') ||
                (current == ']' && lastOpened != '[')) {
                return false;
            }
        }
    }

    // If stack is empty, all brackets were matched correctly
    return top == -1;
}

int main() {
    char s[MAX];
printf(" Nehal Buxy, 25070521185, D1 ");
    printf("Input: s = ");
    // Using scanf with %s to take string input
    scanf("%s", s);

    if (isBalanced(s)) {
        printf("Output: true\n");
        printf("Explanation: All the brackets are well-formed.\n");
    } else {
        printf("Output: false\n");
        printf("Explanation: The expression is not balanced.\n");
    }

    return 0;
}
