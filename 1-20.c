#include<stdio.h>
#include<string.h>
#define MAXLEN 500
#define TAB 8

/********************************************************************************************************
 * Function : detab                                                                                     *
 *                                                                                                      *
 * Return   : char                                                                                      *
 *                                                                                                      *
 * Parameters: str - char array representing the input string                                           *
 *                                                                                                      *
 * Description: The function detab takes an input string and replaces each tab character ('\t')         *
 *              with the appropriate number of spaces to achieve proper tab alignment. The converted    *
 *              string is then printed. The function returns void.                                      *
 *******************************************************************************************************/
char detab(char str[])
{
    int i, j, k =0;
    char str1[MAXLEN];
    int len = strlen(str);

    for(i = 0 ; i < len ; i++)
    {
        if(str[i] == '\t')
        {
            int space = TAB - (k % TAB);
            for(j =0; j< space; j++)
            {
                str1[k] = '_';
                k++;

            }
        }
        else
        {
            str1[k++] = str[i];
        }
    }

    str1[k] = '\0';
    printf("Converted String is: \n%s", str1);

}


/****************************************************************************************************
 * Function : main                                                                                  *
 *                                                                                                  *
 * Description: This is the main function of the program. It prompts the user to enter a string,    *
 *              reads the input string, removes the trailing newline character, and prints the      *
 *              original string. Then, it calls the `detab` function to perform tab conversion      *
 *              on the input string. The converted string is printed within the `detab` function.   *
 *              The function returns 0 to indicate successful execution.                            *
 ***************************************************************************************************/
int main()
{
    char str[MAXLEN];
    char result[MAXLEN];
    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Original String is: \n%s\n", str);

    detab(str);

    return 0;

}
