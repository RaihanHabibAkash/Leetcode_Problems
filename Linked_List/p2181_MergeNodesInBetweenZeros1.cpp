// Problem: Merge Nodes in Between Zeros
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Topics: Singly linked list nodes insertion

/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
 

Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.
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
void insert(ListNode* &newHead, ListNode* &cur, int sum) {
    // Creating new node
    ListNode* newNd = new ListNode(sum);

    // If head is null setting head
    if(newHead == NULL) {
        newHead = newNd;
        cur = newHead;
        return;
    }
    
    // Creating connection of newnode & cur node
    cur->next = newNd;
    cur = cur->next;
}
    ListNode* mergeNodes(ListNode* head) {
        // Sciping first 0
        ListNode* tmp = head->next;

        // Creating new node & pointer of it
        ListNode* newHead = new ListNode;
        ListNode* cur = NULL;
        newHead = NULL;

        int sum = 0;
        while(tmp != NULL) {
            // If val is 0 pushin sum in new node
            if(tmp->val == 0) {
                insert(newHead, cur, sum);
                sum = 0;
            } // or sum+= value of node
            else sum += tmp->val;

            // Iterating
            tmp = tmp->next;
        // While ends
        }

        // Returning new linked list head
        return newHead;

    // Function ends
    }
};