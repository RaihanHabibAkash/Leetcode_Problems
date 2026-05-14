// Problem: Remove Duplicates from Sorted List
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Topics: Singly Linked List, Delete at any

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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

void removeNext(ListNode* &cur) {
    // Deleting node
    ListNode* dltNode = cur->next;

    // Connectin to cur & cur->next->next node
    cur->next = cur->next->next;
    delete dltNode;
}

    ListNode* deleteDuplicates(ListNode* &head) {
        ListNode* cur = head;
        
        // if only no node
        if(head == NULL) return NULL;

        while(cur->next != NULL && cur != NULL) {
            // if two node val is same delete it
            if(cur->val == cur->next->val){
                removeNext(cur);
                continue;
            }
            // Moving the pointer
            cur = cur->next;

        // While ends
        }

        // Return the head
        return head;

    // Function ends
    }
};