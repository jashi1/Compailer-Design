#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
void process_identifier(const char *token);
void process_constant(const char *token);
void process_operator(const char *token);

int main() {
    char c;
    char token[MAX_LENGTH];
    int token_length = 0;

    // Read and process the input
    while ((c = getchar()) != EOF) {
        // Skip redundant spaces, tabs, and newlines
        if (isspace(c)) {
            continue;
        }

        // Process comments
        if (c == '/' && (c = getchar()) == '*') {
            while ((c = getchar()) != EOF) {
                if (c == '*' && (c = getchar()) == '/') {
                    break;
                }
            }
            continue;
        } else if (c == '/' && c == '/') {
            while ((c = getchar()) != EOF && c != '\n') {
                // Skip single-line comments
            }
            continue;
        }

        // Process tokens
        token[token_length++] = c;

        // If the token length exceeds the max length, print and reset
        if (token_length >= MAX_LENGTH) {
            token[token_length] = '\0';
            printf("Token too long: %s\n", token);
            token_length = 0;
            continue;
        }

        if (isspace(c) || c == ';' || c == ',' || c == '(' || c == ')' || c == '{' || c == '}' || c == '+' || c == '-' || c == '*' || c == '/') {
            token[token_length] = '\0';
            if (token_length > 0) {
                // Check if token is an identifier or constant
                if (isalpha(token[0]) || token[0] == '_') {
                    process_identifier(token);
                } else if (isdigit(token[0])) {
                    process_constant(token);
                } else {
                    process_operator(token);
                }
                token_length = 0;
            }
            if (c != ' ' && c != '\t' && c != '\n') {
                // Print operators and punctuators
                char op[2] = {c, '\0'};
                process_operator(op);
            }
        }
    }

    // Process any remaining token
    if (token_length > 0) {
        token[token_length] = '\0';
        if (isalpha(token[0]) || token[0] == '_') {
            process_identifier(token);
        } else if (isdigit(token[0])) {
            process_constant(token);
        } else {
            process_operator(token);
        }
    }

    return 0;
}

// Function to process identifiers
void process_identifier(const char *token) {
    printf("Identifier: %s\n", token);
}

// Function to process constants
void process_constant(const char *token) {
    printf("Constant: %s\n", token);
}

// Function to process operators
void process_operator(const char *token) {
    printf("Operator: %s\n", token);
}

