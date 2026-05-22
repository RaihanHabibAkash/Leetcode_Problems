// Problem: Remove Nth Node From End of List
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Topics: Singly linked list, Slow Fast algoritham

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // If the node is empty
        if(head == NULL) return head;

        // one node only
        if(head->next == NULL && n == 1) {
            delete head;
            head = NULL;
            return head;
        }

        // Use Slow, fast algoritham.
        // Slow will start from 1
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* moreSlow = slow;

        // fast from n'th node
        for(int i = 1; i < n; i++) fast = fast->next;

        while(fast->next != NULL) {
            moreSlow = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // If delete at head
        if(moreSlow == slow) {
            head = head->next;
            delete moreSlow;
            return head;
        }

        // Slow is now at delete node
        ListNode* dltNode = slow;
        // Connecting moreSlow with moreslow->next->next(slow->next)
        moreSlow->next = moreSlow->next->next;
        // Delete the node
        delete dltNode;

        return head;
    }
};