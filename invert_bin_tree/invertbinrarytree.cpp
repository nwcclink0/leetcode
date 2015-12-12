/*************************************************************************
	> File Name: invertbinrarytree.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Dec 2015 09:37:19 PM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode tree_node;

struct TreeNode* invertTree(struct TreeNode* root) 
{
    if(root == NULL)
    {
        return NULL;
    }
    
    tree_node *temp = NULL;
    if((root->left != NULL)||
       (root->right != NULL))
    {
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        if(root->left != NULL)
        {
            invertTree(root->left);
        }
        if(root->right != NULL)
        {
            invertTree(root->right);
        }
    }
    return root;
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

void print_tree_node(tree_node *node)
{
    if(node != NULL) 
    {
        printf("node: %p, node val: %d\n", 
              node, node->val);
        if(node->right != NULL)
        {
            printf("node %p has right node: %p\n", 
                  node, node->right);
            print_tree_node(node->right);
        }

        if(node->left!= NULL)
        {
            printf("node: %p has left node: %p\n", 
                  node, node->left);
            print_tree_node(node->left);
        }
    }
}

int main(int argc, char **argv)
{
    tree_node *root = create_bin_tree_1();
    print_tree_node(root);
    root = invertTree(root);
    print_tree_node(root);
    return 0; 
}
