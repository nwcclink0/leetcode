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

    if((n == 1))
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else if( n == 3)
    {
        return 3;
    }
    else if(n == 4)
    {
        return 5;
    }
    else if (n == 5)
    {
        return 8;
    }
    else if(n == 6)
    {
        return 13;
    }
    int iRet =   climbStairs(n -1) + climbStairs(n - 2);  
    return iRet;
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
