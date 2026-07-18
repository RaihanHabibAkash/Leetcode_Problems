// Problem: Recover Binary Search Tree
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/recover-binary-search-tree/
// Topics: DFS(InOrder) & Vector using Sort in assending
/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
*/



class Solution {
public:
    vector<int> nodes;

    void dfs(TreeNode* root) {
        if(!root) return;

        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }

    void dfsMain(TreeNode* &root, int &index) {
        if(!root) return;

        dfsMain(root->left, index);
        root->val = nodes[index++];
        dfsMain(root->right, index);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(nodes.begin(), nodes.end());

        int idx = 0;
        dfsMain(root, idx);
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