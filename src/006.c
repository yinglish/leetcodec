#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) 
{
    int length = strlen(s);
    int i, j, k;
    int delta1, delta2;
    char *result = (char *)malloc(sizeof(char) * (length + 1));
    //printf("test1\n");
    if (numRows == 1 || length == 1)
    {
        for (i = 0; i < length; ++i)
        {
            result[i] = s[i];
        }
    }
    else 
    {
        for (k = 0, i = 1; i <= numRows; ++i)
        {
            j = 0;
            while ((i + j * (2 * numRows - 2 * i)) <= length && k < length)
            {
                delta1 = i + j * (2 * numRows - 2 * i);
                delta2 = i + j * (2 * numRows - 2);
                if (i != 1 && i != numRows)
                {
                    if (delta1 != delta2)
                    {
                        result[k++] = s[delta1 - 1];
                    }
                        
                }
                if (delta2 <= length)
                {
                    result[k++] = s[delta2 - 1];
                }
                    
                ++j;
            }
        }
    }
    
    result[length] = '\0';

    return result;
}


int main(void)
{
    // printf("%s\n", convert("paypalishiring", 3));
    // printf("%s\n", convert("A", 1));
    // printf("%s\n", convert("AB", 1));
    // printf("%s\n", convert("ABCD", 3));
    printf("%s\n", convert("ABCDEF", 3));
    return 0;
}