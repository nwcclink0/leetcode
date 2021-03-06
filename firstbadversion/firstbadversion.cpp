/*************************************************************************
	> File Name: firstdabversion.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Dec 2015 05:29:50 PM PST
 ************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>


#define BAD 120
bool isBadVersion(int version)
{
    if(version == BAD)
        return true;
    else
        return false;
}

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;
    while(right > left)
    {
        int middle = left + (right - left) / 2;
        if(isBadVersion(middle))
        {
            right = middle; 
        }
        else
        {
            left = middle + 1;
        }
    }
    return left;
}


int main(int argc, char **argv)
{
    int test_pattern = BAD + 1000;
    int result = false;
    for(int i = 0; i < test_pattern; i++)
    {
        result = firstBadVersion(i);
        if(result > 1)
        {
            printf("test result: %d of %d\n", result, i);
            break;
        }
    }
    return 0;
}
