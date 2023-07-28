#include<stdio.h>
#include<string.h>
#define MAXLINE 5


/****************************************************************************************************
 * Function : getline                                                                               *
 *                                                                                                  *
 * Return   : int - Length of the resulting string                                                  *
 *                                                                                                  *
 * Description: Reads characters from the input stream until it encounters the end of file (EOF)    *
 *              or a newline character. It stores the characters in the 's' array and returns the   *
 *              length of the resulting string.                                                     *
 ***************************************************************************************************/
int getline(char s[], int lim)
{
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        s[i] = c;
        i++;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/****************************************************************************************************
 * Function : copy                                                                                  *
 *                                                                                                  *
 * Return   : void                                                                                  *
 *                                                                                                  *
 * Description: Copies characters from the 'from' array to the 'to' array until it encounters the   *
 *              null character '\0'. It performs a character-wise copy and ensures that the 'to'    *
 *              array is properly terminated with a null character.                                 *
 ***************************************************************************************************/

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/****************************************************************************************************
 * Function : main                                                                                  *
 *                                                                                                  *
 * Inputs   : int argc - Number of command-line arguments                                           *
 *            char *argv[] - Array of command-line argument strings                                 *
 *                                                                                                  *
 * Return   : int                                                                                   *
 *                                                                                                  *
 * Description: The main function serves as the entry point of the program. It reads input lines    *
 *              and finds the longest line along with its length.                                   *
 ***************************************************************************************************/

int main(int argc, char *argv[])
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;

    printf("Srting Input: ");
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
     if (max > 0)  // Check if there is a longest line
    {
        if (max > MAXLINE)  // Check if the longest line exceeds the maximum allowed length
        {
            printf("\n\nStorage limit exceeded");
            printf("\nString length: %d", max);
            printf("\nPlease enter a maximum %d length string", MAXLINE);
        }
        else
        {
            printf("\nString length: %d", max);
            printf("\nLongest string is: %s", longest);
        }
    }

    return 0;
}
