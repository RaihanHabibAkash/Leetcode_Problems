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