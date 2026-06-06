// Problem: Diameter of Binary Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/diameter-of-binary-tree/
// Topics: Binary Tree max diamter & height tracking using recurtion

/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/




class Solution {
public:
    int diameter(TreeNode* root, int &mxDiameter) {
        // Base case
        if(!root) return 0;
        
        int l = diameter(root->left, mxDiameter);
        int r = diameter(root->right, mxDiameter);

        mxDiameter = max(l+r, mxDiameter); // Current diameter will be compared with max diameter, and max diameter will be stored
        return max(l, r) + 1; // max height+1 will be return in the next recurtion call
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mxDiameter = 0;
        diameter(root, mxDiameter);

        return mxDiameter;
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