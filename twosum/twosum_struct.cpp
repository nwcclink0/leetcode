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

struct hashTable{
    int iKey;
    int iVal;
};

typedef struct hashTable hash;


void quickSort(hash *nums, int begin, int end)
{
    int i = begin;
    int j = end;
    hash temp = nums[begin];
    if(i < j)
    {
        while(i < j)
        {
            while(i < j && nums[j].iVal > temp.iVal)
            {
                j --;
                if(i < j)
                    nums[i++] = nums[j];
                while(i < j && nums[i].iVal< temp.iVal)
                    i++;
                if(i < j)
                    nums[j--] = nums[i];
            }
            nums[i] = temp;
            quickSort(nums, begin, j-1);
            quickSort(nums, i+1, end);
        }
    }
}

int binSearch(hash *nums, int target, int begin, int end)
{
    while(end >= begin)
    {
        int middle = begin + (end - begin) / 2;
        if(nums[middle].iVal > target)
        {
            end = middle -1;
        }
        else if(nums[middle].iVal < target)
        {
            begin = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target)
{
    if((nums == NULL) || numsSize == 0)
        return NULL;

    int *pOutput = (int*)malloc(sizeof(int) * 2);

    //quick_sort(nums, 0, numsSize);
    int iMax = 0;
    int iSubMax  = 0;
    hash *pHashList = (hash*)malloc(sizeof(hash*) * numsSize);
    for(int j = 0; j < numsSize; j++)
    {
       pHashList[j].iKey = j;
       pHashList[j].iVal = nums[j];
    }

    quickSort(pHashList, 0, numsSize -1);
    for(int i = 0; i < numsSize; i++)
    {
        int temp = target - pHashList[i].iVal;
        int iIdx2 = binSearch(pHashList, temp, i + 1, numsSize);
        if(iIdx2 == -1)
        {
            continue;
        }
        else
        {
            pOutput[0] = pHashList[i].iKey + 1;
            pOutput[1] = pHashList[iIdx2].iKey + 1;
            if(pOutput[0] > pOutput[1])
            {
                int temp1 = pOutput[0];
                pOutput[0] = pOutput[1];
                pOutput[1] = temp1;
            }
        }
    }
    return pOutput;
}
 
int main(int argc, char **argv)
{
    int test[] = {1,5,6,8, 34};
    int iSize = sizeof(test)/ sizeof(int);
    int iSum1 = 2;
    int iSum2 = 3;
    int target = test[iSum1] + test[iSum2];
    int *pRes = twoSum(test, iSize, target);
    
    int iIdx = 0;
    printf("test idx: %d/ %d\n", iSum1 +1, iSum2 + 1);
    for(iIdx; iIdx < 2; iIdx++)
    {
        printf("res idx: %d\n", pRes[iIdx]);
    }
    
    return 0;
}
