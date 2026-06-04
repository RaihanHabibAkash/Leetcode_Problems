// Problem: Binary Tree Right Side View
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Topics: Binary Tree level order traversing & STL pair
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;

        // If empty binary tree
        if(root == NULL) return v;
        
        // Queue of pairs
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 0 });
        int lvl = 0;

        while(!q.empty()) {
        // 1. ber kore ana
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

        // 2. oi node node nia kaj
            if(level == lvl) {
                v.push_back(node->val);
                lvl++;
            }

        // 3. oi node ar children push in the node (Thakle)
            if(node->right) q.push({node->right, level+1});
            if(node->left) q.push({node->left, level+1});
        }

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