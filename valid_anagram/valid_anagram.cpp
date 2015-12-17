/*************************************************************************
	> File Name: valid_anagram.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Dec 2015 01:57:29 AM PST
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) 
{
    if(!s && !t)
        return false;
    
    char *pTempS = s;
    char *pTempT = t;
    
    int iLenS = strlen(pTempS);
    int iLenT = strlen(pTempT);

    if( iLenS != iLenT )
        return false;
    printf("strlen, t: %d, s: %d\n", iLenT, iLenS);

    for(int i = 0; i < iLenS; i++)
    {
        int iIdx_s = i;
        int iIdx_t = iLenS - i -1;
        printf("iIdx_s: %d, iIdx_t: %d\n", iIdx_s, iIdx_t);
        if(s[iIdx_s] != t[iIdx_t])
            return false;
    }
    return true;
}


int main(int argc, char **argv)
{
    char _test1_s[] = "test";
    char _test1_t[] = "tte";
   
    char *test1_s = (char*)malloc(sizeof(char)* strlen(_test1_s));
    char *test1_t = (char*)malloc(sizeof(char)* strlen(_test1_t));
    
    memcpy(test1_s, _test1_s, sizeof(char) * strlen(_test1_t));
    memcpy(test1_t, _test1_t, sizeof(char) * strlen(_test1_t));
    
    bool bAnagram = isAnagram(test1_s, test1_t);
    printf("is Anagram, %d\n", bAnagram);
    return 0;
}
