/*************************************************************************
	> File Name: deleteNode.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Dec 2015 03:56:51 PM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode list_node;


//void quick_sort(list_node *list, int begin, int end)
//{
    //int i = begin;
    //int j = end;
    //list_node *temp = list;
    //if(i < j)
    //{
        //while(i < j)
        //{
            //while(i < j && list[j].val > temp.val)
            //{
                //j --;
                //if(i < j)
                //{
                    //list[i++] = list[j];
                //}
                //while(i < j && list[i].val < temp.val)
                    //i++;
                //if(i < j)
                    //list[j--] = list[i];
            //}
            //list[i] = temp;
            //quick_sort(list, begin, j-1);
            //quick_sort(list, i + 1, end);
        //}
    //}
//}


//void binSearch(list_node *list, int target, int left, 
              //int right)
//{
    //while(right >= left)
    //{
        //int middle = begin + (right - left)/2;
        //if(list[middle].val > target)
        //{
            //right = middle -1;
        //}
        //else if(list[middle].val < target)
        //{
            //left = middle +1;
        //}
        //else
            //return middle;
    //}
    //return -1;
//}

void deleteNode(list_node* node) 
{
    if(node == NULL)
        return;
    list_node *temp = node;
    int iSize = 0;
    while(temp != NULL)
    {
        iSize = iSize + 1;
        temp = temp->next;
    }
    //printf("isize: %d\n", iSize);
    if(iSize >= 1)
    {
        //printf("head node val: %d\n", node->val);
        list_node *remove_node = node;
        node->val = remove_node->next->val;
        node->next = remove_node->next->next;
        /*printf("new head node val: %d\n", node->val);*/
        /*printf("new head node add: %p\n", node);*/
    }
}

int main(int argc, char *argv)
{
    list_node *head = (list_node*)malloc(sizeof(list_node));
    head->val = 1;
    head->next = NULL;
    list_node *temp = head;
    for(int i = 0; i < 2; i ++)
    {
        list_node *node = (list_node*)malloc(sizeof(list_node));
        node->val = i + 2;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("node's value: %d\n", temp->val);
        temp = temp->next;
    }
    printf("before del node's value: %p\n", head);
    deleteNode(head);
    printf("after del node's value: %p\n", head);
    temp = head;
    while(temp != NULL)
    {
        printf("node's value: %d\n", temp->val);
        temp = temp->next;
    }
    return 0;
}
