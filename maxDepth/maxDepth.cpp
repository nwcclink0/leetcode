/*************************************************************************
	> File Name: maxDepth.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Dec 2015 02:40:45 PM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define max(a,b) \
        ({__typeof__(a) _a = (a); \
         __typeof__(b) _b = (b); \
         _a > _b  ? _a : _b;})
typedef struct TreeNode tree_node;

int maxDepth(tree_node* root)
{
    if(root == NULL) 
        return 0;

    int iRight = maxDepth(root->right);
    int iLeft = maxDepth(root->left);

    return max(iRight, iLeft) + 1;
}

int main(int argc, char **argv)
{
    tree_node *root = (tree_node*)malloc(sizeof(tree_node));
    tree_node *temp = root;
    for(int i = 0; i < 10; i++)
    {
        tree_node *node = (tree_node*)malloc(sizeof(tree_node));
        temp->left = node;
        temp = temp->left;
    }

    temp = root;
    for(int i = 0; i < 3; i++)
    {
        tree_node *node = (tree_node*)malloc(sizeof(tree_node));
        temp->right = node;
        temp = temp->right;
    }

    
    int iMax = maxDepth(root);
    printf("max depth: %d\n", iMax);
}
