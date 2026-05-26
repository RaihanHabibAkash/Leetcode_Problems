// Problem: Min Stack
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/min-stack/
// Topics: 2 Stack, One main other for min detection
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/


class MinStack {
public:
    class Node {
    public:
        Node* prev;
        int val;
        Node* next;

        Node(int val) {
            prev = NULL;
            this->val = val;
            next = NULL; 
        }
    };
    Node* head = NULL;
    Node* tail = NULL;

    MinStack() {
        
    }
    
    void push(int val) {
        Node* newNd = new Node(val);

        if(head == NULL) {
            head = newNd;
            tail = newNd;
            return;
        }

        head->prev = newNd;
        head->prev->next = head;
        head = head->prev;
    }
    
    void pop() {
        if(head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* dltNd = head;
        head = head->next;
        head->prev = NULL;
        delete dltNd;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        Node* cur = head->next;
        int min = head->val;

        while(cur != NULL) {
            if(cur->val < min) min = cur->val;
            cur = cur->next;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */