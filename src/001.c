#include <stdio.h>
#include <stdlib.h>


/* brute-force */
int* twoSum1(int* nums, int numsSize, int target) 
{
    int i, j, found = 0;
    int *ans = (int *)malloc(sizeof(int) * 2);
    for (i = 0; i < numsSize - 1; ++i)
    {
        for (j = i + 1; j < numsSize; ++j)
        {
            if ((nums[i] + nums[j]) == target)
            {
                ans[0] = i;
                ans[1] = j;
                found = 1;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    return ans;
}

int main(void)
{
    int i;
    int test[] = {1, 3, 8, 2, 12, 4, 13};
    int *pAns;
    pAns = twoSum1(test, 7, 11);

    printf("The array is:\n");
    for (i = 0; i < 7; ++i)
    {
        printf("%d ", test[i]);
    }
    printf("\n");
    printf("target is: %d, and the answer is: %d, %d\n", 11, pAns[0] + 1, pAns[1] + 1);
    return 0;
}