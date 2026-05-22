// Problem: Middle of the Linked List
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Topics: Singly Linked List, Recurtion
/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
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

    int sizeOfList(ListNode* headCpy) {
        // Base case
        if(headCpy == NULL) return 0;

        // Main case
        return 1 + sizeOfList(headCpy->next);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int mid = 0;
        int listSize = sizeOfList(head);
        
        // If one node return it
        if(listSize == 1) return head;

        // For even, odds Nodes same operation
        mid = (listSize / 2) + 1;

        // Iterating thow that indes
        for(int i = 1; i < mid; i++) cur = cur->next;

        // Return that pointer
        return cur;

    // Function end
    }
};