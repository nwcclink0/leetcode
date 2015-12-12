/*************************************************************************
	> File Name: sametree.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Dec 2015 01:15:05 PM PST
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>


struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode tree_node;

bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if(p == NULL && q != NULL)
        return false;
    if(p != NULL && q == NULL)
        return false;
    if(p == NULL && q == NULL)
        return true;

    bool isSameLeaf = (p == q)? true : false;
    bool isSameValue = p->val == q->val ? true : false;
    bool isSameleft = p->left == q->left ? true : false;
    bool isSameright = p->right == q->right ? true : false;
    printf("p->right: %p, q->right: %p, q->left: %p, q->left: %p\n",
            p->right, q->right,
            p->left, q->left);
    //if(isSameleft && isSameright && isSameValue)
    //if(isSameLeaf && isSameValue)
    if(isSameValue)
    {
        if((p->right == NULL) && (p->left == NULL) &&
            (q->right == NULL) && (q->left == NULL))
        {
            return true; 
        }

        bool sameRight = true;
        bool sameLeft = true;
        if((p->right != NULL) && (q->right != NULL))
        { 
            sameRight = isSameTree(p->right, q->right);
        }
        else if((p->right != NULL) && (q->right == NULL))
        {
            sameRight = false;
        }
        else if((p->right == NULL) && (q->right != NULL))
        {
            sameRight = false;
        }

        if((p->left != NULL) && (q->left != NULL))
        {
            sameLeft = isSameTree(p->left, q->left);
        }
        else if((p->left == NULL) && (q->left != NULL))
        {
            sameLeft = false;
        }
        else if((p->left != NULL) &&  (q->left == NULL))
        {
            sameLeft = false;
        }
        return (sameRight && sameLeft);
    }
    return false;
}

tree_node *create_bin_tree_0()
{
    tree_node *head = (tree_node*)malloc(sizeof(tree_node));
    head->left = 0;
    head->right = 0;
}

tree_node *create_bin_tree_1()
{
    tree_node *head = (tree_node*)malloc(sizeof(tree_node));
    head->left =  (tree_node*)malloc(sizeof(tree_node));   
    head->right = (tree_node*)malloc(sizeof(tree_node)); 
    head->left->val= 0;
    head->right->val= 1;
    head->right->right = (tree_node*)malloc(sizeof(tree_node)); 
    head->right->right->val= 3;
    head->val = 2;
}

tree_node *create_bin_tree_2()
{
    tree_node *head = (tree_node*)malloc(sizeof(tree_node));
    head->left =  (tree_node*)malloc(sizeof(tree_node));   
    head->right = (tree_node*)malloc(sizeof(tree_node)); 
    head->left->val= 0;
    head->right->val= 4;
    head->right->right = (tree_node*)malloc(sizeof(tree_node)); 
    head->right->right->val= 3;
    head->val = 2;
}



int main(int argc, char **argv)
{
    tree_node *tree_0 = create_bin_tree_0();
    tree_node *tree_1 = create_bin_tree_0();
    
    tree_node *tree_2 = create_bin_tree_1(); 
    tree_node *tree_3 = create_bin_tree_1();

    tree_node *tree_4 = create_bin_tree_2();
    tree_node *tree_5 = create_bin_tree_2();

    bool isSame = isSameTree(tree_0, tree_1);
    printf("test case 1: %d\n", isSame);

    isSame = isSameTree(tree_2, tree_3);
    printf("test case 2: %d\n", isSame);

    isSame = isSameTree(tree_0, tree_2);
    printf("test case 3: %d\n", isSame);
 
    isSame = isSameTree(tree_4, tree_5);
    printf("test case 4: %d\n", isSame);
}

