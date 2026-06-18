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
class Solution {
public:
    void pushV(TreeNode* root, vector<int>& v) {
        // base case
        if(!root) return;

        pushV(root->left, v);
        pushV(root->right, v);

        v.push_back(root->val);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        pushV(root,v);
        sort(v.begin(), v.end());
        int minDif = INT_MAX;
        for(int i = 0; i < v.size()-1; i++) minDif = min(minDif,abs(v[i] - v[i+1]));
        return minDif;
    }
};