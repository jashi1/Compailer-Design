#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int whitespace_count = 0;
    int newline_count = 0;

    printf("Enter text (Ctrl+D to end input):\n");

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            if (c == ' ' || c == '\t') {
                whitespace_count++;
            } else if (c == '\n') {
                newline_count++;
            }
        }
    }

    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);

    return 0;
}

