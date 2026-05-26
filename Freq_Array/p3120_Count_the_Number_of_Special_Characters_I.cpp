// Problem: Count the Number of Special Characters I
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/
// Topics: 2 Freq array
/*
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.

 

Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        // Checking and inserting in freq array
        for(char c : word) {
            if(c >= 'A' && c <= 'Z') freq1[c-'A']++;
            else freq2[c-'a']++;
        }

        // Count of special numbers
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(freq1[i] > 0 && freq2[i] > 0) cnt++;
        }

        return cnt; 
    }
};