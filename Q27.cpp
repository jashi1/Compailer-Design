#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function prototypes
void process_line(const char *line);
void process_comment(const char *line, int start, int end);

// Function to check if a line is a comment
void process_line(const char *line) {
    int len = strlen(line);
    int i = 0;

    // Check for single-line comments
    if (line[i] == '/' && line[i + 1] == '/') {
        printf("Single-line comment: %s\n", line);
        return;
    }

    // Check for multi-line comments
    while (i < len) {
        if (line[i] == '/' && line[i + 1] == '*') {
            int start = i;
            i += 2; // Move past "/*"
            while (i < len) {
                if (line[i] == '*' && line[i + 1] == '/') {
                    process_comment(line, start, i + 1);
                    i += 2; // Move past "*/"
                    break;
                }
                i++;
            }
            // If no "*/" found, the comment is not closed
            if (i >= len) {
                printf("Unterminated multi-line comment starting at index %d: %s\n", start, line);
            }
        } else {
            i++;
        }
    }
}

// Function to process and print a comment substring
void process_comment(const char *line, int start, int end) {
    char comment[MAX_LENGTH];
    strncpy(comment, line + start, end - start + 1);
    comment[end - start + 1] = '\0'; // Null-terminate the substring
    printf("Multi-line comment: %s\n", comment);
}

int main() {
    char line[MAX_LENGTH];

    printf("Enter lines of text (Ctrl+D to end input):\n");

    while (fgets(line, sizeof(line), stdin)) {
        // Remove newline character from the end if present
        line[strcspn(line, "\n")] = '\0';
        
        // Process each line to check if it's a comment
        process_line(line);
    }

    return 0;
}

