#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidMobileNumber(char number[]);

int main() {
    char mobileNumber[20];
    printf("Enter the mobile number: ");
    scanf("%s", mobileNumber);

    if (isValidMobileNumber(mobileNumber)) {
        printf("The mobile number is valid.\n");
    } else {
        printf("The mobile number is invalid.\n");
    }

    return 0;
}

int isValidMobileNumber(char number[]) {
    // Check length
    int length = strlen(number);
    if (length != 10) {
        return 0;
    }

    // Check if all characters are digits
    for (int i = 0; i < length; i++) {
        if (!isdigit(number[i])) {
            return 0;
        }
    }

    return 1;
}