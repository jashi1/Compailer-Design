#include <stdio.h>

void check(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        printf("%c is an UpperCase character\n", ch);
    else if (ch >= 'a' && ch <= 'z')
        printf("%c is a LowerCase character\n", ch);
    else
        printf("%c is not an alphabetic character\n", ch);
}

int main() {
    char ch;
    ch = 'A';
    check(ch);
    ch = 'a';
    check(ch);
    ch = '0';
    check(ch);
    return 0;
}
