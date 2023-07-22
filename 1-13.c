#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************************/
/* Function : main, printHistogram              `                                */
/* Inputs   : 1. argc -- The number of parameters provided to the main function  */
/*            2. argv -- The pointer to the input string array of parameters     */
/* Variables: List all the important variables used in the function              */
/* Return   :  =0 -- Success	                                                 */
/*          :  <0 -- Failed                                                      */
/* Note     : This function reads a string from the user and calls the           */
/*            printHistogram function to print the word length histogram.        */                     */
/*********************************************************************************/

#define MAXLEN 500
#define MAX_WORD_LENGTH 10

void printHistogram(char line[])
{
    int i = 0, j, number_of_words = 0;
    int wordLengths[MAX_WORD_LENGTH + 1] = {0};
    int length = strlen(line);
    char word[MAXLEN];
    int wordIndex = 0;

    // Loop through each character in the input string
    while (i < length)
    {
        if (line[i] != ' ')
        {
            word[wordIndex] = line[i];
            wordIndex++;
        }
        else
        {
            word[wordIndex] = '\0';
            wordIndex = 0;
            int wordLen = strlen(word);

            // Update the frequency count based on word length
            if (wordLen <= MAX_WORD_LENGTH)
            {
                wordLengths[wordLen]++;
            }
            else
            {
                wordLengths[MAX_WORD_LENGTH]++;
            }

            number_of_words++;
        }
        i++;
    }

    // Process the last word if it doesn't end with a space
    if (wordIndex > 0)
    {
        word[wordIndex] = '\0';
        int wordLen = strlen(word);

        // Update the frequency count based on word length
        if (wordLen <= MAX_WORD_LENGTH)
        {
            wordLengths[wordLen]++;
        }
        else
        {
            wordLengths[MAX_WORD_LENGTH]++;
        }

        number_of_words++;
    }

    printf("Words = %d\n", number_of_words);

    printf("Character Count Histogram in Horizontal==>\n");
    // Print the horizontal histogram
    for (i = 1; i <= MAX_WORD_LENGTH; ++i)
    {
        printf("%2d: ", i);

        for (j = 0; j < wordLengths[i]; ++j)
        {
            printf("%c ", 254);
        }
        printf("\n");
    }

    printf("\nCharacter Count Histogram in Vertical==>\n");
    int maxCount = 0;
    // Find the maximum frequency count
    for (i = 1; i <= MAX_WORD_LENGTH; ++i)
    {
        if (wordLengths[i] > maxCount)
        {
            maxCount = wordLengths[i];
        }
    }

    // Print the vertical histogram
    for (i = maxCount; i > 0; --i)
    {
        for (j = 1; j <= MAX_WORD_LENGTH; ++j)
        {
            if (wordLengths[j] >= i)
            {
                printf("  %c ", 254);
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }

    // Print the word length values below the vertical histogram
    for (i = 1; i <= MAX_WORD_LENGTH; ++i)
    {
        printf(" %2d ", i);
    }
    printf("\n");
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
