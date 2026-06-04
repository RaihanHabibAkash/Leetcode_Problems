// Problem: Maximum Depth of Binary Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Topics: Binary Tree, Recurtion
/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/


class Solution {
public:
    int max_depth(TreeNode* root) {
        // Base case
        if(root == NULL) return 0;

        int l = max_depth(root->left);
        int r = max_depth(root->right);
        return max(l,r) + 1;
    }
    int maxDepth(TreeNode* root) {
        return max_depth(root);
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