// Problem: Symmetric Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/symmetric-tree/
// Topics: Binary Tree DFS(Depth First search)


/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/



class Solution {
public:
    bool check(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        else if(!root1 || !root2) return false;

        if(root1->val != root2->val) return false;

        bool l = check(root1->left, root2->right);
        bool r = check(root1->right, root2->left);

        return l && r;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
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