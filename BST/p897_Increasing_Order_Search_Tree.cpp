// Problem: Increasing Order Search Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/increasing-order-search-tree/
// Topics: In order Traversal in BST. And create and new node at right side
/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
*/



class Solution {
public:
    TreeNode* mainRt = NULL, *cur = NULL;

    void insert(int val) {
        TreeNode* node;
        if(!mainRt) {
            node = new TreeNode(val);
            mainRt = node;
            cur = node;
        }
        else {
            node = new TreeNode(val);
            cur->right = node;
            cur = cur->right;
        }
    } 

    void check(TreeNode* root) {
        // Base case
        if(!root) return;

        check(root->left);
        insert(root->val);
        check(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        check(root);
        return mainRt;
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