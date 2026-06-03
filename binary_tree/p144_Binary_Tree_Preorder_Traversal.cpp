// Problem: Binary Tree Preorder Traversal
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Topics: Binary Tree Pre order traversal, Recurtion
/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/


class Solution {
public:
    void preorder_traversal(TreeNode* root, vector<int> &v) {
        // Base case
        if(!root) return;

        v.push_back(root->val); // root
        preorder_traversal(root->left, v); // left
        preorder_traversal(root->right, v); // right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        // Inserting value in vector in pre order
        preorder_traversal(root, v);

        return v;
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