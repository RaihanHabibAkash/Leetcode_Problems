// Problem: Two Sum
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/two-sum/
// Topics: 2 Pointers, Vector
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Copint vector
        vector<int> cpy(nums.begin(), nums.end());

        // For getting the value & index
        int l = 0, r = cpy.size()-1,
        leftVal, rightVal;

        // Sorting the value
        sort(cpy.begin(), cpy.end());

        // Two pinter technique
        while(l < r) {
            // Match the nidex
            if(target == cpy[l]+cpy[r]) {
                leftVal = cpy[l];
                rightVal = cpy[r];
                break;
            }
            else if(target < cpy[l]+cpy[r]) r--;
            // target > cpy[l]+cpy[r]
            else l++;
        }

        // Checking for Index in main vector
        l = -1, r = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(l == -1) {
                if(leftVal == nums[i] || rightVal == nums[i]) l = i;
            }
            else {
                if(leftVal == nums[i] || rightVal == nums[i]) r = i;
            }
        }
        
        // For returning
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;

    // Vector ends
    }
};