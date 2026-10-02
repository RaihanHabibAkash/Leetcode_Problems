// Problem: Longest Valid Parentheses
// Platform: LeetCode
// Difficulty: Hard
// Link: https://leetcode.com/problems/longest-valid-parentheses/
// Topics: Stack, stack tracker
/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' && !st.empty() && st.top().first == '(')
                st.pop();
            else st.push({s[i], i});
        }
        
        bool vis[30005];
        memset(vis, true, sizeof(vis));
        while(!st.empty()) {
            vis[st.top().second] = false;
            st.pop();
        }

        int cnt = 0, mx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(vis[i]) cnt++;
            else {
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
        mx = max(mx, cnt);
        return mx;
    }
};