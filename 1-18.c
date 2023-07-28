#include<stdio.h>
#include<string.h>
#define MAXLINE 500

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
 * Function : main                                                                                  *
 *                                                                                                  *
 * Inputs   : int argc - Number of command-line arguments                                           *
 *            char *argv[] - Array of command-line argument strings                                 *
 *                                                                                                  *
 * Return   : int                                                                                   *
 *                                                                                                  *
 * Description: The main function serves as the entry point of the program. It reads input lines    *
 *              and finds the length.                                                               *
 ***************************************************************************************************/

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int len, i, j;

    printf("Input String is: ");
    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("\nInput String length is: %d\n", len);

        for (i = len - 2; i >= 0; --i)
        {
            if (line[i] != ' ' && line[i] != '\t')
            {
                break;
            }
        }

        line[i + 1] = '\n'; // Add back the newline character
        line[i + 2] = '\0'; // Terminate the line after the newline character

        if (line[0] != '\n')
        {
            printf("\nOutput String is: %s", line);
            printf("\nOutput String length is: %d\n", len - 1 - (len - 1 - strlen(line))); // Subtract trailing blanks length
        }
    }



    return 0;
}

