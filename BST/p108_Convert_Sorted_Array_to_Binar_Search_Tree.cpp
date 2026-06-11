// Problem: Convert Sorted Array to Binary Search Tree
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Topics: Array to BST conversation

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

class Solution {
public:
    TreeNode* arrayToBst(vector<int> v, int l, int r) {
        // Base case
        if(l > r) return NULL;

        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(v[mid]);
        TreeNode* myLeft = arrayToBst(v, l, mid-1);
        TreeNode* myRight = arrayToBst(v, mid+1, r);

        // Connection
        root->left = myLeft;
        root->right = myRight;

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBst(nums, 0, nums.size()-1);
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