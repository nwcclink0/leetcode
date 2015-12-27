/*************************************************************************
	> File Name: isBalanced.c
	> Author: Moby
	> Mail: 9712579@gmail.com
	> Created Time: Sat 26 Dec 2015 07:49:59 PM PST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode tree_node;

#define max(a,b) \
        ({__typeof__(a) _a = (a); \
         __typeof__(b) _b = (b); \
         _a > _b  ? _a : _b;})

int maxDepth(tree_node* root)
{
    if(root == NULL) 
        return 0;

    int iRight = maxDepth(root->right);
    int iLeft = maxDepth(root->left);

    return max(iRight, iLeft) + 1;
}

bool isBalanced(struct TreeNode* root) 
{
    if(!root)
        return true;

    tree_node *temp_root = root;
    tree_node *temp_right = NULL;
    tree_node *temp_left = NULL;
    temp_left = temp_root->left;
    temp_right = temp_root->right;
    int iRightDepth = maxDepth(temp_right);
    int iLeftDepth = maxDepth(temp_left);
    int iDeff = iRightDepth - iLeftDepth;
    if((iDeff > 0 && iDeff <= 1) || (iDeff < 0 && iDeff >= -1)
       || (iDeff == 0))
    {
        bool rightBal = isBalanced(temp_right);
        bool leftBal = isBalanced(temp_left);
        return (rightBal && leftBal);
    }
    else
    {
        return false;
    }
}

bool isBalanced_wt_height(tree_node *root,int *height)
{
    if(root == NULL)
    {
        return true;
    }
   
    int right_height = 0;
    int left_height = 0;
    bool isBalRight = isBalanced_wt_height(root->right, &right_height);
    bool isBalLeft = isBalanced_wt_height(root->left, &left_height);
    
    if(right_height > left_height)
    {
        *height = right_height + 1;
    }
    else
    {
        *height = left_height + 1;
    }
    if((right_height - left_height >= 2) ||
       (left_height - right_height >= 2))
    {
        return false;
    }
    return (isBalRight && isBalLeft);
}

bool isBalanced_opt(tree_node *root)
{
    int iHeight=0;
    bool isBal = isBalanced_wt_height(root, &iHeight);
    return isBal;
}

tree_node* newNode(int data)
{
    tree_node* node = (tree_node*)
    malloc(sizeof(tree_node));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);

}

int main(int argc, char **argv)
{
    tree_node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    bool isBal = isBalanced_opt(root);
    printf("is Balance: %d\n", isBal);
    return 0; 
}
