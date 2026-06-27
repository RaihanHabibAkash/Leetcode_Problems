// Problem: Design Linked List
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/design-linked-list/
// Topics: Doubly linked List delete at all & Insert at all
/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/



class MyLinkedList {
public:
class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};
    Node* head = NULL;
    Node* tail = NULL;
    int nodes = 0;

    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index >= nodes || nodes < 1) return -1;

            Node* cur = head;
            for(int i = 0; i < index; i++) cur = cur->next;
            return cur->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        nodes++;
        if(!head) {
            head = node;
            tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = head->prev;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        nodes++;
        if(!head) {
            head = node;
            tail = node;
            return;
        }

        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    
    void insertAtAny(int index, int val) {
        Node* cur = head;
        for(int i = 1; i < index; i++) cur = cur->next;
        Node* node = new Node(val);
        node->next = cur->next;
        node->prev = cur;
        node->next->prev = node;
        cur->next = node;
        nodes++;
    }

    void dltAtHead() {
        if(nodes == 1) {
            head = NULL;
            tail = NULL;
            return;
        }
        head = head->next;
        head->prev = NULL;
    }

    void dltAtTail() {
        if(nodes == 1) {
            head = NULL;
            tail = NULL;
            return;
        }
        tail = tail->prev;
        tail->next = NULL;
    }
    
    void addAtIndex(int index, int val) {
        if(index > nodes) return;
        else if(index == 0) addAtHead(val);
        else if(index == nodes) addAtTail(val);
        else insertAtAny(index, val);
    }

    void dltAtAny(int index) {
        Node* cur = head;
        for(int i = 1; i < index; i++) cur = cur->next;

        cur->next = cur->next->next;
        if(cur->next) cur->next->prev = cur;
    }
    
    void deleteAtIndex(int index) {
        if(index+1 > nodes) return;
        else if(0 == index) dltAtHead();
        else if(index+1 == nodes) dltAtTail();
        else dltAtAny(index);
        nodes--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */