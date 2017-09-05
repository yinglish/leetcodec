#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestPalindrome(char* s) 
{
    int flags[1000][1000] = {0};
    int k, i;
    int length = strlen(s);
    int resultLength = 0;
    int resultLeft = 0, resultRight = 0;
    for (k = 0; k < length; ++k)
    {
        for (i = 0; (i + k) < length; ++i)
        {
            if ((i + k) == i)
                flags[i][i + k] = 1;
            else if ((i + k) == (i + 1))
                flags[i][i + k] = (flags[i][i] && (s[i] == s[i + 1]));
            else
                flags[i][i + k] = (flags[i + 1][i + k - 1] && (s[i] == s[i + k]));
        }
    }

    for (k = 0; k < length; ++k)
    {
        for (i = 0; (i + k) < length; ++i)
        {
            if (flags[i][i + k])
            {
                if ((k + 1) > resultLength)
                {
                    resultLength = k + 1;
                    resultLeft = i;
                    resultRight = i + k;
                }
            }
        }
    }

    // add to solve out of time
    if (resultLength == length)
        return s;

    char *result = (char *)malloc(sizeof(char) * (resultRight - resultLeft + 2));
    for (i = 0, k = resultLeft; k <= resultRight; ++k, ++i)
    {
        result[i] = s[k];
    }
    result[resultRight - resultLeft + 1] = '\0';

    return result;
}

int main()
{
    char str1[] = "babad";
    char str2[] = "cbbd";
    printf("%s\n", longestPalindrome(str1));
    printf("%s\n", longestPalindrome(str2));
    return 0;
}