// Problem: Minimum Depth of Binary Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Topics: Binary Tree traversing using recurtion & logic

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/



class Solution {
public:
    int min_depth(TreeNode* root) {
        // Base case 
        if(!root) return 0;

        if(!root->left && !root->right) return 1;

        int l = min_depth(root->left);
        int r = min_depth(root->right);

        if(!l || !r) return max(l, r) + 1;
        else return min(l, r) + 1;
    }
    int minDepth(TreeNode* root) {
        return min_depth(root);
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