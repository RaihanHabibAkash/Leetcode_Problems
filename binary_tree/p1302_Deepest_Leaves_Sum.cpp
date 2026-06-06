// Problem: Deepest Leaves Sum
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/deepest-leaves-sum/
// Topics: Binary Tree level order traversal & pair for level tracking
/*
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
*/


 */
class Solution {
public:
    void dep_sum(TreeNode* root, int &lvl, int &sum) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level != lvl) {
                lvl = level;
                sum = 0;
            }

            sum += node->val;

            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int sum = 0, lvl = 0;
        dep_sum(root, lvl, sum);

        return sum;
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