#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************************/
/* Function : main, printHistogram                                               */
/* Inputs   : 1. argc -- The number of parameters provided to the main function  */
/*            2. argv -- The pointer to the input string array of parameters     */
/* Variables: List all the important variables used in the function              */
/* Return   :  =0 -- Success	                                                 */
/*          :  <0 -- Failed                                                      */
/* Note     : This function reads a string from the user and calls the           */
/*            printHistogram function to print the character count histogram.    */                    */
/*********************************************************************************/

#define MAXLEN 500
#define MAX_WORD_LENGTH 10

void printHistogram(char line[])
{
    int i, j, k, number_of_char = 0, nw, nn;
    int length = strlen(line);
    int word[256] = {0}; // Increase the size to 256 for ASCII characters

    printf("Character count: %d\n", length);

    for (i = 0; i < length; i++)
    {
        word[line[i]]++; // Increment the count for the corresponding character
    }

    printf("Horizontal:\n");
    for (i = 1; i < 256; ++i) // Start from 1 as ASCII characters start from 1
    {
        if (word[i] > 0) // Only print if count is greater than 0
        {
            printf("%c  ", i);

            for (j = 0; j < word[i]; ++j)
            {
                printf("%c ", 254);
            }
            printf("\n");
        }
    }

    printf("\nWord Lengths Histogram in Vertical==>\n");
    for (k = MAX_WORD_LENGTH; k > 0; k--)
    {
        printf("%d", k);
        for (i = 0; i < 256; i++)
        {
            if (word[i] >= k && i != '\n' && i != ' ')
            {
                printf("  %c ", 254);
            }
            else if (word[i] != 0)
            {
                printf("    ");
            }
        }
        putchar('\n');
    }

    for (i = 0; i < 256; i++)
    {
        if (word[i] > 0 && i != '\n' && i != ' ')
        {
            printf("  %2c", i);
        }
    }
}

int main()
{
    char line[MAXLEN];
    printf("Enter a string: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';

    printHistogram(line);

    return 0;
}
