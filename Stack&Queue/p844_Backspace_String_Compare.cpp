// Problem: Backspace String Compare
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/backspace-string-compare/
// Topics: Stack
/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/



class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1, st2;
        for(char c : s) {
            // If the stack is already empty
            if(c == '#' && st1.empty()) continue;

            // Removing the last char
            if(c == '#' && !st1.empty()) st1.pop();
            else st1.push(c);
        }
        for(char c : t) {
            // If the stack is already empty
            if(c == '#' && st2.empty()) continue;

            // Removing the last char
            if(c == '#' && !st2.empty()) st2.pop();
            else st2.push(c);
        }

        // Checker
        if(st1 == st2) return true;
        else return false;
    }
};