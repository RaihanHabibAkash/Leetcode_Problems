// Problem: Validate Binary Search Tree
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/validate-binary-search-tree/
// Topics: BST or not using In Order Traversal(DFS)
/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/


class Solution {
public:
    TreeNode* prev = NULL;
    bool inOrder(TreeNode* root) {
        if(!root) return true;

        bool l = inOrder(root->left);

        if(prev) {
            if(root->val <= prev->val) return false;
        }
        prev = root;

        bool r = inOrder(root->right);

        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        return inOrder(root);
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
