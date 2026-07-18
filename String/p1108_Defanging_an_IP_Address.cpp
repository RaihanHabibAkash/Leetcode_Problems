// Problem: Defanging an IP Address
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/defanging-an-ip-address/
// Topics: String & Loops

/*
Easy
Topics
premium lock icon
Companies
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 

Constraints:

The given address is a valid IPv4 address.
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(int i = 0; i < address.size(); i++) {
            if(address[i] == '.') s += "[.]";
            else s+= address[i]; 
        }
        return s;
    }
};