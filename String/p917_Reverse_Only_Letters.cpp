// Problem: Reverse Only Letters
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/reverse-only-letters/
// Topics: String & Loop indexing

/*
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'
*/

class Solution {
public:
    bool valid(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
            return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
            if(valid(s[i]) && valid(s[j]))
                swap(s[i], s[j]);
            else if(valid(s[i]) && !valid(s[j])) i--;
            else if(!valid(s[i]) && valid(s[j])) j++;
        }
        return s;
    }
};