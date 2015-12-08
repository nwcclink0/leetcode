/*************************************************************************
    > File Name: twosum.cpp
    > Author: 
    > Mail: 
    > Created Time: Fri 04 Dec 2015 05:44:27 AM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *data, int left, int right)
{
    int pivot, i, j;

    if(left > right)
        return;

    pivot = abs(data[left]);

    i = left + 1;
    j = right;
    while(1)
    {
        while(i <= right)
        {
            if(abs(data[i])> pivot)
            {
                break;
            }

            i = i + 1;
        }
        while(j > left)
        {
            if(abs(data[j]) < pivot) 
            {
                break;
            }

            j = j - 1;
        }

        if(i > j )
        {
            break;
        }

        swap(&data[i], &data[j]);
    } 

    swap(&data[left], &data[j]);
    quick_sort(data, left, j - 1);
    quick_sort(data, j + 1, right);
}

int* twoSum(int* nums, int numsSize, int target)
{
    if((nums == NULL) || numsSize == 0)
        return NULL;

    int *pOutput = (int*)malloc(sizeof(int) * 2);

    int *pTemp = (int*)malloc(sizeof(int) *numsSize);
    memcpy(pTemp, nums, numsSize * sizeof(int));
    quick_sort(pTemp, 0, numsSize -1);
    int iSize = abs(pTemp[numsSize-1]) + abs(pTemp[numsSize -2]); 
    for(int idx = 0; idx < numsSize; idx ++)
    {
        printf("pTemp: %d\n", pTemp[idx]);
    }
    //printf("size: %d, sizeof(int): %d\n", iSize, sizeof(int));

    int *pHash = (int*)malloc(2* iSize * sizeof(int));
    memset(pHash, 0x0, 2* iSize * sizeof(int));
    //for(int idx1 = 0; idx1 < (nums[1]+iSize + 2); idx1++)
    /*for(int idx1 = 0; idx1 < 32; idx1++)*/
    //{
        //printf("pHash: %d\n", pHash[idx1]);
   /* }*/
    for(int i = 0; i < numsSize; i++)
    {
        int key = nums[i] + iSize;
        int value = pHash[key];
        printf("key: %d, value: %d\n", key, value);
        if(pHash[nums[i] + iSize] == 0)
        {
            pHash[target - nums[i] + iSize] = i + 1;
            printf("%d's nums: %d\n", i, nums[i]+ iSize);
        }
        else
        {
            pOutput[0] = pHash[nums[i] + iSize];
            pOutput[1] = i + 1;
            printf("index 1: %d, index 2: %d\n", pHash[nums[i]], i);
            break;;
        }
    }
    return pOutput;
}
 
int main(int argc, char **argv)
{
    //int test[] = {-1,-5,-6,-8, 10};
    //int test[] = {4,1,5,5};
    int test[] = {0,0,2,4};
    int iTarge = test[1] + test[0];
    int iSize = sizeof(test)/sizeof(int);
    printf("test array size: %d\n", iSize);
    int *pRes = twoSum(test, iSize, iTarge);
    printf(" test ; index 1: %d, index 2: %d\n", pRes[0], pRes[1]);
    return 0;
}
