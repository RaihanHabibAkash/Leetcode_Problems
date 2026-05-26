// Problem: Remove All Adjacent Duplicates In String
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Topics: Stack

/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the
*/


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(st.empty()) st.push(s[i]);
            else if(st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }

        // Value are reversed so fixing it
        stack<int> st1;
        while(!st.empty()) {
            st1.push(st.top());
            st.pop();
        }
        int index = 0;
        string newS;
        while(!st1.empty()) {
            newS.push_back(st1.top());
            st1.pop();
        }

        return newS;
    }
};