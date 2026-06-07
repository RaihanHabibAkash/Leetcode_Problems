// Problem: Univalued Binary Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/univalued-binary-tree/
// Topics: Binary Tree Preorder traversal
/*
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 

Example 1:


Input: root = [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: root = [2,2,2,5,2]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100
*/


class Solution {
public:
    bool check(TreeNode* root, int val) {
        // Base case
        if(!root) return true;
        
        if(root->val != val) return false;

        bool l = check(root->left, val);
        bool r = check(root->right, val);

        return l && r;
    }
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return check(root, val);
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