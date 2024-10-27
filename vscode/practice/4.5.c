#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int isValidBSTHelper(struct TreeNode* node, long min, long max) 
{   
    if( node == NULL ) {
        return 1;
    }

    if( node->val <= min || node->val >= max) {
        return 0;
    }

    return isValidBSTHelper(node->left, min, node->val) &&
            isValidBSTHelper(node->right, node->val, max);

};

int isValidBST(struct TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
} 

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main(){
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);
    root->left->left->left = createNode(10);

    // 检查这棵树是否是合法的 BST
    if (isValidBST(root)) {
        printf("该二叉树是合法的二叉搜索树。\n");
    } else {
        printf("该二叉树不是合法的二叉搜索树。\n");
    }

    return 0;
}
