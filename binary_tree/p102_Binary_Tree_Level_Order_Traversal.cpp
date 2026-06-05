// Problem: Binary Tree Level Order Traversal
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Topics: Binary Tree level order traversal & STL pair to level tracker & STL vector
/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> newV;
        int lvl = 0;
        if(!root) return v;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
        // 1. Ber kore nia asha
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

        // 2. oi node nia kaj
            if(level != lvl) {
                v.push_back(newV);
                lvl++;
                newV.clear();
            }
            newV.push_back(node->val);

        // 3. oi node ar children push in the queue(thakle)
            if(node->left) q.push({ node->left, level+1 });
            if(node->right) q.push({ node->right, level+1 });
        }

        // Inserting last vector
        v.push_back(newV);
        newV.clear();

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