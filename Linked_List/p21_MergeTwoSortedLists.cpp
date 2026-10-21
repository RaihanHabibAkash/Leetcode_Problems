// Problem: Merge Two Sorted Lists
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
// Topics: Singly Linked List, STL Vector

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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

void insertAtTail(ListNode* &head, ListNode* &tail, int value) {
    // Creating the new node
    ListNode* newNode = new ListNode(value);

    // If the node is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting new node with tail
    tail->next = newNode;
    // new node is tail now
    tail = tail->next;
}

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Pointer for tracing of two pointer head
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        // Vector for sorting all values
        vector<int> v;

        // Inserting all value form linked list to vector
        while(cur1 != NULL) {
            v.push_back(cur1->val);
            cur1 = cur1->next;
        }
        while(cur2 != NULL) {
            v.push_back(cur2->val);
            cur2 = cur2->next;
        }

        // Sorting it
        sort(v.begin(), v.end());

        // Pushing all value from vector to new Singly linked list
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(int i = 0; i < v.size(); i++) {
            insertAtTail(head, tail, v[i]);
        }
        
        // Return new Node head
        return head;

    // function ends
    }
};