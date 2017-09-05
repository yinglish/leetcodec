#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) 
{
    int hashTable[256] = {0};
    //printf("%d\n", sizeof(hashTable));
    int longest = 0;
    int curLongest = 0;
    int i, length, j;
    if (s != NULL)
    {
        length = strlen(s);
        for (i = 0; i < length; ++i)
        {
            j = i;
            while (j < length)
            {
                if (!hashTable[s[j]])
                {
                    curLongest++;
                    //printf("%d\n", longest);
                    hashTable[s[j]] = 1;
                    j++;
                    //printf("%c %d\n", s[i], hashTable[s[i]]);
                }
                else
                {
                    if (curLongest > longest)
                    {
                        longest = curLongest;
                    }
                    curLongest = 0; // first time you put this statement in the if, which is wrong!
                    memset(hashTable, 0, sizeof(hashTable));
                    break;
                }
            }
            // if (!hashTable[s[i]])
            // {
            //     curLongest++;
            //     //printf("%d\n", longest);
            //     hashTable[s[i]] = 1;
            //     //printf("%c %d\n", s[i], hashTable[s[i]]);
            // }
            // else
            // {
            //     if (curLongest > longest)
            //     {
            //         longest = curLongest;
            //     }
            //     curLongest = 0;
            //     i--;
            //     memset(hashTable, 0, sizeof(hashTable));
            // }
        }
        if (curLongest > longest)
            longest = curLongest;
    }

    return longest;
}

int main()
{
    char str1[] = "abcabcbb";
    char str2[] = "bbbbb";
    char str3[] = "";
    char *str4 = NULL;
    printf("%d\n", lengthOfLongestSubstring(str1));
    printf("%d\n", lengthOfLongestSubstring(str2));
    printf("%d\n", lengthOfLongestSubstring(str3));
    printf("%d\n", lengthOfLongestSubstring(str4));

    return 0;
}