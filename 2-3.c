#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(const char hex[]) {
    int result = 0;
    int i;
    int startIndex = 0;

    // Check if the input has "0x" prefix
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        startIndex = 2;
    }

    // Process each character of the hexadecimal string
    for (i = startIndex; hex[i] != '\0'; i++) {
        char c = hex[i];
        int value = 0;

        // Convert character to integer value
        if (isdigit(c)) {
            value = c - '0';
        } else if ((c>= 'a' && c<= 'f') || (c>='A' && c<= 'F')) {
            value = toupper(c) - 'A' + 10;
        } else {
            // Invalid character encountered
            printf("Invalid input: %c\n", c);
            return -1; // Return an error value
        }

        // Update the result by shifting and adding the value
        result = (result * 16) + value;
    }

    return result;
}

int main() {
    char hex[100];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = htoi(hex);

    if (decimal != -1) {
        printf("Decimal representation: %d\n", decimal);
    }

    return 0;
}
