/*
	> File Name: reverseList.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Dec 2015 03:59:47 PM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef ListNode
struct ListNode
{
    int val;
    struct ListNode *next;
};
#endif
typedef ListNode Node;
struct ListNode* reverseList(ListNode* head) 
{
    if(head == NULL)
        return NULL;

    Node *pPrevHead = head;
    Node *l = head->next;
    pPrevHead->next = NULL;
    while( l != NULL)
    { 
        struct ListNode *pTempNode = l->next;
        l->next = pPrevHead;
        pPrevHead = l;
        l = pTempNode;
    }
    return pPrevHead;
}

int main(int argc, char **argv)
{
    ListNode *testNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode *pStart = testNode;

    ListNode *pTemp= testNode;
    for(int i = 0; i < 5; i++)
    {
        pTemp->val = i;
        pTemp->next = (ListNode*)malloc(sizeof(ListNode));
        pTemp = pTemp->next;
    }

    ListNode *pPrintNode = testNode;
    for(int j = 0; j < 5; j++)
    {
        printf("val: %d\n", pPrintNode->val);
        pPrintNode = pPrintNode->next;
    }
    testNode = reverseList(testNode);
    pPrintNode = testNode;
    for(int j = 0; j < 5; j++)
    {
        printf("val: %d\n", pPrintNode->val);
        pPrintNode = pPrintNode->next;
    }
    return 0;
}
