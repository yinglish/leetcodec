#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int low, lowIndex, high;
    int i = 0, j = 0;

    lowIndex = (nums1Size + nums2Size) / 2;
    while (i < nums1Size && j < nums2Size)
    {
        lowIndex--;
        if (nums1[i] < nums2[j])
        {
            if (lowIndex == 0)
            {
                low = nums1[i++];
            }
            else if (lowIndex == -1)
            {
                high = nums1[i++];
                break;
            }
            else
                ++i;
        }
        else
        {
            if (lowIndex == 0)
            {
                low = nums2[j++];
            }
            else if (lowIndex == -1)
            {
                high = nums2[j++];
                break;
            }
            else
                ++j;
        }
    }

    while (lowIndex > -1 && i < nums1Size)
    {
        lowIndex--;
        if (lowIndex == 0)
        {
            low = nums1[i++];
        }
        else if (lowIndex == -1)
        {
            high = nums1[i++];
            break;
        }
        else
            ++i;
    }

    while (lowIndex > -1 && j < nums2Size)
    {
        lowIndex--;
        if (lowIndex == 0)
        {
            low = nums2[j++];
        }
        else if (lowIndex == -1)
        {
            high = nums2[j++];
            break;
        }
        else
            ++j;
    }

    //printf("%d %d\n", low, high);

    if ((nums1Size + nums2Size) % 2)
    {
        return (double)high;
    }
    else
    {
        return (double)(low + high) / 2;
    }
}



int main()
{
    int a[] = {1, 3};
    int b[] = {2};
    int c[] = {1, 2};
    int d[] = {3, 4};
    printf("%lf\n", findMedianSortedArrays(a, 2, b, 1));
    printf("%lf\n", findMedianSortedArrays(c, 2, d, 2));
    return 0;
}