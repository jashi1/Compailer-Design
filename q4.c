#include <stdio.h>
#include <ctype.h>

void identifyVowelsAndConsonants(char str[]);

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    identifyVowelsAndConsonants(str);

    return 0;
}

void identifyVowelsAndConsonants(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                printf("%c is a vowel\n", str[i]);
            } else {
                printf("%c is a consonant\n", str[i]);
            }
        }
        i++;
    }
}
