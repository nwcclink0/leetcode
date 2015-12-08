/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Dec 2015 02:39:16 PM PST
 ************************************************************************/

#include<iostream>
#include <stdio.h>
using namespace std;

// [1,2,3,3,4] / [] / [-1,2,3,4] / [4,2,3,1]/ [3363636,1, 2, 3] / [0,0,0,0] 
int removeDuplicate(int *nums, int numsSize)
{
    if(numsSize <= 0) 
    {
        return 0; 
    }
    if(nums == NULL)
        return 0;

    int iTest = *nums;
    nums++;
    int iCount = 1;
    int *retAry = nums;

    for(int i = 1; i < numsSize; i++)
    {
        if(iTest != *nums) 
        {
            iCount++;
            *retAry = *nums;
            retAry++;
            iTest = *nums;
        }
        nums++;
    }
    return iCount;
}


int main(int argc, char** argv)
{
    int test_ary[]= {1,2,3,4,4,4,4,5};
    int iArySize = sizeof(test_ary)/sizeof(int);
    int iRet = removeDuplicate(test_ary, iArySize);
    printf("printf result\n");
    for(int i = 0; i < iArySize; i++)
    {
        printf("%d\n", test_ary[i]);
    }
    printf("iRet: %d\n", iRet);
    return 0;
}
