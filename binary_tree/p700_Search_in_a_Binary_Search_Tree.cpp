// Problem: Search in a Binary Search Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Topics: Binary tree Pre order traversal

/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
*/


class Solution {
public:
    bool flag = false;
    void preOrder(TreeNode* root, int val, TreeNode* &node) {
        // Base case
        if(!root) return;
        
        if(flag) return;

        if(root->val == val) {
            node = root;
            flag = true;
            return;
        }
        preOrder(root->left, val, node);
        preOrder(root->right, val, node);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        TreeNode* node = NULL;
        preOrder(root, val, node);

        return node;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */