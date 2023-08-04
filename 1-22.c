#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

/*****************************************************************************************************
 * Function : maxWordLength                                                                          *
 *                                                                                                   *
 * Return   : int                                                                                    *
 *                                                                                                   *
 * Parameters: c - char array representing the input string                                          *
 *                                                                                                   *
 * Description: The function maxWordLength takes an input string and calculates the maximum length   *
 *              of words in the string. It iterates through the characters in the string and keeps   *
 *              track of the current word length. Whenever a space or newline character is           *
 *              encountered, it compares the current word length with the maximum length seen so far *
 *              and updates the maximum length if necessary. Finally, it returns the maximum word    *
 *              length found.                                                                        *
 ****************************************************************************************************/

int maxWordLength(char c[]) {
    int i;
    int maxLen = 0;
    int len = 0;
    int length = strlen(c);

    for (i = 0; i < length; i++) {
        if (c[i] != ' ' && c[i] != '\n') {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
            }
            len = 0;
        }
    }

    return maxLen;
}

/****************************************************************************************************
 * Function : foldLine                                                                              *
 *                                                                                                  *
 * Return   : void                                                                                  *
 *                                                                                                  *
 * Parameters: line - char array representing the input line                                        *
 *             maxLen - integer specifying the maximum line length to fold at                       *
 *                                                                                                  *
 * Description: The function foldLine takes an input line and a maximum line length and prints      *
 *              the folded lines based on the maximum length. If the length of the line is shorter  *
 *              than or equal to the maximum length, it is printed as is. Otherwise, it folds the   *
 *              line at appropriate spaces or tabs to fit within the maximum length. The folded     *
 *              lines are printed one by one. The function returns void.                            *
 ****************************************************************************************************/

void foldLine(char line[], int maxLen)
{
    int i;
    int length = strlen(line);

    if (length <= maxLen)
    {
        printf("%s\n", line);  // No need to fold if line is shorter than or equal to max length
    } else
    {
        int i = 0;
        int j = maxLen - 1;

        while (j < length)
        {
            // Find the previous space or tab from j
            while (j >= i && line[j] != ' ' && line[j] != '\t')
            {
                j--;
            }

            // If no space or tab found, fold at j
            if (j < i)
            {
                j += maxLen;
            }

            // Print the folded line
            for (i = i; i <= j; i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");

            i = j + 1;
            j = i + maxLen - 1;
        }

        // Print the remaining part of the line
        if (i < length)
        {
            for (i = i; i < length; i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}

/****************************************************************************************************
 * Function : main                                                                                  *
 *                                                                                                  *
 * Return   : int                                                                                   *
 *                                                                                                  *
 * Parameters: None                                                                                 *
 *                                                                                                  *
 * Description: This is the main function of the program. It prompts the user to enter a line of    *
 *              text, calculates the maximum word length in the line, and then folds the line into  *
 *              segments of maximum length, printing each segment on a new line.                    *
 ***************************************************************************************************/

int main()
{
    char line[MAX_LENGTH];
    printf("Input:\n");
    fgets(line, sizeof(line), stdin);


    int maxLen = maxWordLength(line);
    printf("\nMaximum word length: %d\n", maxLen);


    foldLine(line, maxLen);

    return 0;
}
