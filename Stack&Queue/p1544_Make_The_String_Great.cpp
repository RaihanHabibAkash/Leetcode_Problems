// Problem: Make The String Great
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/make-the-string-great/
// Topics: 2 stacks logics, String
/*
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:

Input: s = "s"
Output: "s"
 

Constraints:

1 <= s.length <= 100
s contains only lower and upper case English letters.
*/

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c : s) {
            if(st.empty()) st.push(c);
            else if(st.top()-'a' == c-'A' || st.top()-'A' == c-'a') st.pop();
            else st.push(c);
        }

        // String are reversed so fixing it
        stack<char> st1;
        s.clear();
        while(!st.empty()) {
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty()) {
            s.push_back(st1.top());
            st1.pop();
        }

        return s;
    }
};