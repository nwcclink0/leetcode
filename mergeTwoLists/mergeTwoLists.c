/*************************************************************************
	> File Name: mergeTwoLists.c
	> Author: Moby
	> Mail: 9712579@gmail.com
	> Created Time: Thu 24 Dec 2015 02:24:01 PM PST
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
/**
*  * Definition for singly-linked list.
*   * struct ListNode {
*    *     int val;
*     *     struct ListNode *next;
*      * };
*       */
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode list_node;
void addNode(list_node *head, list_node *addNode)
{
    addNode->next = head->next;
    head->next = addNode;
}

void removeNode(list_node *head)
{
    head->next = head->next->next;
}

list_node* mergeAns(list_node *l1, list_node *l2)
{
    list_node *temp = (list_node*)malloc(sizeof(list_node));
    temp->val = -1;
    list_node *head = temp;
    while(l1 && l2)
    {
        printf("l1: %p, l2: %p\n", l1, l2);
        if(l1->val <= l2->val)
        {
            temp->next = l1;
            l1 = l1->next;
            printf(" case 1 l1: %p, l2: %p\n", l1, l2);
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
            printf(" case 2 l1: %p, l2: %p\n", l1, l2);
        }
        temp = temp->next;
        temp->next = NULL;
    }
    if(l1 == NULL)
    {
        temp->next = l2;
    }
    else
    {
        temp->next = l1;
    }
    list_node *delNode = head;
    head = head->next;
    free(delNode);
    return head;
}

list_node* create_l1()
{
    list_node *head = (list_node*)malloc(sizeof(list_node));
    list_node *temp = head;
    head->val = 0;
    int valAry[] = {1,3,5,7,9,11};
    int i = 0;
    for(i = 0; i < 7; i++)
    {
        temp->next = (list_node*)malloc(sizeof(list_node));
        temp->next->val = valAry[i];
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
list_node* create_l2()
{
    list_node *head = (list_node*)malloc(sizeof(list_node));
    list_node *temp = head;
    head->val = 0;
    int i = 0;
    int valAry[] = {2,4,6,8,10,12};
    for(i = 0; i < 7; i++)
    {
        temp->next = (list_node*)malloc(sizeof(list_node));
        temp->next->val = valAry[i];
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
list_node* create_l3()
{
    list_node *head = (list_node*)malloc(sizeof(list_node));
    head->val = 2;
    head->next = NULL;
    return head;
} 
list_node* create_l4()
{
    list_node *head = (list_node*)malloc(sizeof(list_node));
    head->val = 1;
    head->next = NULL;
    return head;
}
int main(int argc, char **argv)
{
    list_node *list_1 = create_l1();
    list_node *temp = list_1;
    while(temp->next != NULL)
    {
        printf("temp val: %d\n", temp->val);
        temp = temp->next;
    }
    list_node *list_2 = create_l2();
    temp = list_2;
    while(temp->next != NULL)
    {
        printf("temp val: %d\n", temp->val);
        temp = temp->next;
    }
    temp = mergeAns(list_2, list_1);
    while(temp->next != NULL)
    {
        printf("temp val: %d\n", temp->val);
        temp = temp->next;
    } 
    printf("==================\n");
    list_node *l3 = create_l3();
    list_node *l4 = create_l4();
    temp = mergeAns(l3, l4);
    while(temp!= NULL)
    {
        printf("temp val: %d, add: %p, next: %p\n", temp->val, temp, temp->next);
        temp = temp->next;
    }
    return 0;
}
