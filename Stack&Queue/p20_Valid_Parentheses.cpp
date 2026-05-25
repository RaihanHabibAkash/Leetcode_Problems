// Problem: Valid Parentheses
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-parentheses/
// Topics: Stack, conditions based
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:
*/




class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            // Open brackers push in stack
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else  { // Closing bracket checking
                // if the stack empty we can check
                if(st.empty()) return false;

                // Checking brackets order is same
                if(st.top() == '(' && c == ')') st.pop();
                else if(st.top() == '{' && c == '}') st.pop();
                else if(st.top() == '[' && c == ']') st.pop();
                else return false;
            // Else ends
            }
        // Loop ends
        }
        
        // All brackets are mathced
        if(st.empty()) return true;
        else return false;
    }
};