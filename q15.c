#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the email address is valid
bool isValidEmail(const char *email) {
    // Find the position of '@'
    const char *atPos = strchr(email, '@');
    
    if (atPos == NULL || strchr(atPos + 1, '@') != NULL) {
        // No '@' or more than one '@'
        return false;
    }
    
    // Ensure there is at least one character before and after '@'
    if (atPos == email || *(atPos + 1) == '\0') {
        return false;
    }
    
    // Find the position of '.'
    const char *dotPos = strchr(atPos + 1, '.');
    
    if (dotPos == NULL) {
        // No '.' after '@'
        return false;
    }
    
    // Ensure there is at least one character after '.' and before '@'
    if (*(dotPos + 1) == '\0' || *(dotPos - 1) == '@') {
        return false;
    }
    
    return true;
}

int main() {
    char email[256];

    printf("Enter the email address: ");
    if (fgets(email, sizeof(email), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    email[strcspn(email, "\n")] = '\0';

    if (isValidEmail(email)) {
        printf("\"%s\" is a valid email address.\n", email);
    } else {
        printf("\"%s\" is not a valid email address.\n", email);
    }

    return 0;
}
