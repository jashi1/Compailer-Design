#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to process and print operators
void process_operator(char op) {
    switch (op) {
        case '+':
            printf("Operator: %c (Addition)\n", op);
            break;
        case '-':
            printf("Operator: %c (Subtraction)\n", op);
            break;
        case '*':
            printf("Operator: %c (Multiplication)\n", op);
            break;
        case '/':
            printf("Operator: %c (Division)\n", op);
            break;
        default:
            printf("Unknown character: %c\n", op);
            break;
    }
}

// Function to tokenize and identify operators
void analyze_input(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // Skip whitespace
        if (isspace(c)) {
            continue;
        }

        // Check if the character is one of the arithmetic operators
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            process_operator(c);
        } else {
            // Print unknown characters
            printf("Unknown character: %c\n", c);
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter an arithmetic expression: ");
    if (fgets(input, sizeof(input), stdin)) {
        // Remove newline character if present
        //input[strcspn(input, "\n")] = '\0';

        // Analyze the input
        analyze_input(input);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    return 0;
}

