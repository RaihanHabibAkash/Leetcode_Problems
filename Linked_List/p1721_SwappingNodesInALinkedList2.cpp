// Problem: Swapping Nodes in a Linked List
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Topics: Slow fast algoritham for Singly linked list

/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/



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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Creating slow & fast pointer for tracking
        ListNode* slow = head;
        ListNode* fast = head;

        // Takig fast to 1st k'th node
        for(int i = 1; i < k; i++) fast = fast->next;

        // Pointer for saving fitst k'th
        ListNode* first = fast;

        // Taking fast to last node, so slow will stop in last k'th node
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Slow is now in the from last k'th node
        ListNode* second = slow;

        // Swaping value
        swap(first->val, second->val);

        // Returing the head
        return head;

    // Functions ends
    }
};