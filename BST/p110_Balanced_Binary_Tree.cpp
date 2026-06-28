// Problem: Balanced Binary Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/balanced-binary-tree/
// Topics: DFS & Depth abs dif logic

/*
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/



class Solution {
public:
    bool flag = true;
    int depth(TreeNode* root) {
        if(!root) return 0;
        if(!flag) return 0;

        int l = depth(root->left);
        int r = depth(root->right);

        if(abs(l - r) > 1) flag = false;

        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = 0, r = 0;
        if(root->left) l += depth(root->left);
        if(root->right) r += depth(root->right);

        if(!flag) return false;
        else if(abs(l - r) > 1) return false;
        else return true;
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