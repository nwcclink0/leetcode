/*************************************************************************
	> File Name: containsDuplicate.c
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Dec 2015 03:53:32 PM PST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    if(*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

bool hashFind(int *nums, int iSize)
{
    if((nums == NULL) || (iSize == 0))
    {
        return false;
    }

    int hasSize = 1 << 20;
    bool *hashTable = (bool*)malloc(hasSize * sizeof(bool));
    memset(hashTable, 0x0, hasSize * sizeof(bool));
   
    bool found = false;
    for(int i = 0; i < iSize; i++)
    {
        if(hashTable[nums[i] + iSize] == false)
        {
            hashTable[nums[i] + iSize] = true;
        }
        else
        {
            found = true;
            break;
        }
    }
    return found;
}

int partition(int *nums, int left, int right, int pivotIdx, bool *found)
{
    int pivot = nums[pivotIdx];
    swap(&nums[pivotIdx], &nums[right]);
    int sortIdx = left;
    for(int i = left; i < right-1; i++)
    {
        if(nums[i] < pivot)
        {
            swap(&nums[sortIdx], &nums[i]);
            sortIdx = sortIdx + 1;
        }
        else if(nums[i] == pivot)
        {
            *found = true;
        }
    }
    swap(&nums[right], &nums[sortIdx]);
    return sortIdx;
}

bool quick_dup2(int *nums,int left,int right)
{
    bool found1 = false;
    bool found2 = false;
    if(right > left) 
    {
        int pivot = nums[left];
        bool found = false;
        int pivotIdx = partition(nums, left, right, left, &found);
        if(found == true)
            return true;
        found1 = quick_dup2(nums, left, pivotIdx - 1);
        found2 = quick_dup2(nums, pivotIdx +1, right);
    }
    return (found1 || found2);
}

bool containsDuplicate(int* nums, int numsSize)
{
    if(nums == NULL)
        return false;

    bool found = hashFind(nums, numsSize);
    //bool found = quick_dup2(nums,0, numsSize -1);
    return found;
}

int *create_test_ary_1()
{
    int *ary = (int*)malloc(sizeof(int)
                           * 4);
    ary[0] = 1;
    ary[1] = 2;
    ary[2] = 3;
    ary[3] = 4;

    return ary;
}

int *create_test_ary_2()
{
    int *ary = (int*)malloc(sizeof(int)
                           * 7);
    ary[0] = 0;
    ary[1] = 8;
    ary[2] = 0;
    ary[3] = 6;
    ary[4] = 5;
    ary[5] = 9;
    ary[6] = 19;

    return ary;
}

int main(int argc, char **argv)
{
    int *test_1 = create_test_ary_1();
    int *test_2 = create_test_ary_2();
    int isDuplicate = containsDuplicate(test_1, 4);
    printf("%d\n", 1 << 8);
    printf("1 isDuplicate: %d\n", isDuplicate);
    isDuplicate = containsDuplicate(test_2, 7);
    printf("2 isDuplicate: %d\n", isDuplicate);
    
    free(test_1);
    free(test_2);
    return 0; 
}
