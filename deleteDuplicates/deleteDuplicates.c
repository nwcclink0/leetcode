/*************************************************************************
	> File Name: deleteDuplicates.c
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Dec 2015 02:54:10 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode list_node;

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL)
        return NULL;
    
    list_node *test_node= head;
    list_node *prev_node = NULL; 
    list_node *remove_node = NULL;
    while(test_node != NULL)
    {
        /*printf("head: %p\n", head);*/
        if(prev_node != NULL)
        {
            if(prev_node->val == test_node->val) 
            {
                remove_node = test_node;
                /*test_node->next = remove_node->next->next;*/
                prev_node->next = test_node->next;
                test_node = prev_node->next;
                if(test_node != NULL)
                {
                    test_node->next = prev_node->next->next;
                    /*printf("test node: %p,test_node->next: %p\n",*/
                           /*test_node, test_node->next);*/
                }
                /*printf("===========\n");*/
                /*printf("need to remove: %d, address: %p\n",*/
                       /*remove_node->val,*/
                       /*remove_node);*/
                /*printf("===========\n");*/
                continue;
            }
        }
        prev_node = test_node;
        prev_node->next = test_node->next;
        test_node = test_node->next; 
        /*if((test_node != NULL) || (test_node->next != NULL))*/
        /*{*/
            /*printf("test_node: %p, val: %d,"*/
                /*"test_node->next: %p, val: %d,"*/
                /*"prev_node: %p,"*/
                /*"val: %d\n", test_node, test_node->val,*/
               /*test_node->next,*/
               /*test_node->next->val,*/
               /*prev_node, prev_node->val);*/
           
        /*}*/
    }
    return head;
}

list_node *create_node_list_1()
{
    int iSize = 10;
    list_node *head = (list_node*)
                        malloc(sizeof(list_node));
    list_node *temp = head;
    for(int i = 0; i < iSize; i++) 
    {
        list_node *node = 
            (list_node*)malloc(sizeof(list_node));
        node->val = i;
        if(i == 3 || i == 4)
        {
            node->val = 3;
        }
        temp->next = node;
        temp = temp->next;
        printf("create node: %p, val: %d\n", 
               node, node->val);
    }
    return head;
}

list_node *create_node_list_2()
{
    int iSize = 10;
    list_node *head = (list_node*)
                        malloc(sizeof(list_node));
    head->val = 1;
    list_node *temp = head;
    printf("create head: %p\n", head);
    for(int i = 0; i < iSize; i++) 
    {
        list_node *node = 
            (list_node*)malloc(sizeof(list_node));
        node->val = 1;
        temp->next = node;
        temp = temp->next;
        printf("create node: %p, val: %d, next: %p\n", 
               node, node->val, node->next);
    }
    return head;
}


int main(int argc, char **argv)
{
    list_node *nodelist = create_node_list_1();
    list_node *nodelist_1 = create_node_list_2();
    list_node *result_node = deleteDuplicates(nodelist);
    
    list_node *print_node = NULL;
    print_node = result_node;
    while(print_node->next != NULL)
    {
        printf("node add: %p, val: %d\n", print_node,
              print_node->val);
        
        print_node = print_node->next;
    }
    print_node = nodelist_1;
    while(print_node->next != NULL)
    {
        printf("node: %p, val: %d,, node->next: %p\n",
              print_node, print_node->val, print_node->next);
        print_node = print_node->next;
    }
    result_node = deleteDuplicates(nodelist_1);
    print_node = result_node;
    while(print_node != NULL)
    {
        printf("node add: %p, val: %d\n", print_node,
              print_node->val);
        
        print_node = print_node->next;
    }
    return 0; 
}
