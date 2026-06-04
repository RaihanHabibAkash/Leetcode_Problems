// Problem: Find Bottom Left Tree Value
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-bottom-left-tree-value/
// Topics: Binary Tree level order traversal

/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return 0;

        // Queue of Node*
        queue<TreeNode*> q;
        q.push(root);
        int left = NULL;

        while(!q.empty()) {
        // 1. Ber kore ana
            TreeNode* node = q.front();
            q.pop();

        // 2. oi node nia kaj
            left = node->val;

        // 3. children push queue te (thakle)
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }

        return left;
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