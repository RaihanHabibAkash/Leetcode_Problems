// Problem: Convert Sorted List to Binary Search Tree
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Topics: Solved using Recurtion & Slow fast technique 
/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
*/


class Solution {
public:
    TreeNode* insert(ListNode* first, ListNode* last) {
        ListNode* slow = first, *fast = first;
        while(fast != last && fast->next != last) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);

        TreeNode* l, *r;
        if(slow != first) l = insert(first, slow);
        else l = NULL;
        if(slow->next != last && slow != last) r = insert(slow->next, last);
        else r = NULL;

        node->left = l;
        node->right = r;

        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return insert(head, NULL);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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