// Problem: Maximum Product of Three Numbers
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Topics: Vector & -1 logic with max

/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size()-1;

       return max(nums[0] * nums[1] * nums[2], nums[0] * nums[n] * nums[n-1]);
    }
};