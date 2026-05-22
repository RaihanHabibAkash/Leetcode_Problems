// Problem: Sort List
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/sort-list/
// Topics: Singly Linked List, STL list

/*
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

class Solution {
public:
list<int> l;
    ListNode* sortList(ListNode* &head) {
        // Inserting all value in STL list
        ListNode* cur = head;
        while(cur != NULL) {
            l.push_back(cur->val);
            cur = cur->next;
        }

        // Sort this
        l.sort();

        // Inserting sort value in ListNode
        cur = head;
        while(cur != NULL) {
            cur->val = l.front();
            cur = cur->next;
            l.pop_front();
        }
        return head;
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