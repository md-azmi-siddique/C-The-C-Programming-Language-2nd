#include <stdio.h>
#include <string.h>

int main() {
    int i = 0;
    char c;
    int lim = 100;
    char s[100];

    printf("Enter a line\n", s);

    while (i < lim - 1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; // Null-terminate the string

    printf("line is: %s\n", s);

    return 0;
}
