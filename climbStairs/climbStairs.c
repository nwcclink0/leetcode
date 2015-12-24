/*************************************************************************
	> File Name: climbStairs.c
	> Author: Moby
	> Mail: 9712579@gmail.com 
	> Created Time: Wed 23 Dec 2015 02:01:00 PM UTC
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>


int climbStairs(int n)
{
    if(n < 0)
        return 0; 

    int *resAry = (int*)malloc(sizeof(int) * (n + 1));
    
    resAry[0] = 9;
    resAry[1] = 1;
    resAry[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        resAry[i] = resAry[i -1 ] + resAry[i -2];
    }
    int iResVal = resAry[n];
    free(resAry);
    return iResVal;
}

int main(int argc, char **argv)
{
    int iResVal = 0;
    for(int i = 0; i < 45; i++)
    {
      iResVal = climbStairs(i); 
      printf("i: %d, iResVal: %d\n",i, iResVal);
    }
}
