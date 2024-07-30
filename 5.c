#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Array of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long",
    "register", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is a valid identifier
int isIdentifier(const char *str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

// Function to tokenize the input string and classify tokens
void classifyTokens(const char *input) {
    char token[100];
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isalnum(input[i]) || input[i] == '_') {
            token[j++] = input[i];
        } else {
            if (j != 0) {
                token[j] = '\0';
                if (isKeyword(token)) {
                    printf("Keyword: %s\n", token);
                } else if (isIdentifier(token)) {
                    printf("Identifier: %s\n", token);
                } else {
                    printf("Unknown: %s\n", token);
                }
                j = 0;
            }
        }
        i++;
    }
    // Check for the last token
    if (j != 0) {
        token[j] = '\0';
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isIdentifier(token)) {
            printf("Identifier: %s\n", token);
        } else {
            printf("Unknown: %s\n", token);
        }
    }
}

int main() {
    char input[1000];
    printf("Enter the code:\n");
    fgets(input, sizeof(input), stdin);

    classifyTokens(input);

    return 0;
}