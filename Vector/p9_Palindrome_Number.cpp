// Problem: Palindrome Number
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/palindrome-number/
// Topics: Vector
/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        vector<int> v;
        while(x != 0) {
            v.push_back(x % 10);
            x /= 10;
        }

        for(int i = 0, j = v.size()-1; i < j; i++, j--) {
            if(v[i] != v[j]) return false;
        }

        return true;
    }
};