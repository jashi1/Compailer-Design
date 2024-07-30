#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Function to validate the date
bool isValidDate(int day, int month, int year) {
    // Check year range
    if (year < 1900 || year > 2100) {
        return false;
    }

    // Check month range
    if (month < 1 || month > 12) {
        return false;
    }

    // Days in each month
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check day range
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

int main() {
    char input[11]; // Buffer to hold the date input in DD/MM/YYYY format
    int day, month, year;

    printf("Enter the Date of Birth (DD/MM/YYYY): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Parse the date from the input string
    if (sscanf(input, "%2d/%2d/%4d", &day, &month, &year) != 3) {
        printf("Invalid input format. Please use DD/MM/YYYY format.\n");
        return 1;
    }

    if (isValidDate(day, month, year)) {
        printf("The date %02d/%02d/%04d is valid.\n", day, month, year);
    } else {
        printf("The date %02d/%02d/%04d is invalid.\n", day, month, year);
    }

    return 0;
}
