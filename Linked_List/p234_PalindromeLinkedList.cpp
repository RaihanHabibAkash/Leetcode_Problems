// Problem: Palindrome Linked List
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Topics: Singly Linked List Recurtion & 2 Pointers
/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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

bool checkPal(ListNode* &left, ListNode* rightCpy) {
    // Base case
    if(rightCpy == NULL) return true;

    // Main case, it will go at the last node. than checking
    bool flag = checkPal(left, rightCpy->next);

    // If the flag is one time returns false it will always returns false
    if(!flag) return false;
    
    // Checking (left=firstNode)==(with rightCpy=lastNode)
    if(left->val == rightCpy->val) {
        // Left pointer will move right side for each time
        left = left->next;
        return true;
    }
    else return false;
}
    bool isPalindrome(ListNode* &head) {
        // create an poiter for cur
        ListNode* cur = head;

        // Check palindrome
        return checkPal(cur, cur);
    }
};