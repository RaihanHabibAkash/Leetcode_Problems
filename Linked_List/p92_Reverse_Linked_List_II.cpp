// Problem: Reverse Linked List II
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/reverse-linked-list-ii/
// Topics: Singly Linked List & Recurtion with logic
/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
*/


class Solution {
public:
    ListNode* slow = NULL,* fast = NULL;
    bool flag = false;
    void getNd(ListNode* cur, int left, int right) {
        while(cur) {
            left--; right--;

            if(left == 0) slow = cur;
            if(right == 0) fast = cur;
            cur = cur->next;
        } 
    }
    void rev(ListNode* &s, ListNode* &f) {
        if(f == fast->next) return;

        // Recurtion call
        rev(s, f->next);

        // Swap utile s & f meets
        if(flag) return;
        else if(s == f || f->next == s) {
            flag = true;
            return;
        }

        // Swaping & s is moving foward while (f will backward, Recurtion)
        swap(s->val, f->val);
        s = s->next;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        getNd(head, left, right);
        rev(slow, slow);
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