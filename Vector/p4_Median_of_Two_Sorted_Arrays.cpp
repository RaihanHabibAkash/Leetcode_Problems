// Problem: Median of Two Sorted Arrays
// Platform: LeetCode
// Difficulty: Hard
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Topics: 2 pointers

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), 
        sz2 = nums2.size(),
        mid = (sz1 + sz2) / 2;
        bool even;
        if( (sz1 + sz2) % 2) even = false;
        else even = true;
        
        int l = 0, r = 0;
        double m1 = 0.0, m2 = 0.0;
        for(int i = 0; i <= mid; i++) {
            if(l >= nums1.size()) {
                if(even && i == mid-1) m1 = nums2[r];
                if(i == mid) m2 = nums2[r];

                r++;
            }
            else if(r >= nums2.size()) {
                if(even && i == mid-1) m1 = nums1[l];
                if(i == mid) m2 = nums1[l];

                l++;
            }
            else if(nums1[l] < nums2[r]) {
                if(even && i == mid-1) m1 = nums1[l];
                if(i == mid) m2 = nums1[l];

                l++;
            }
            else{
                if(even && i == mid-1) m1 = nums2[r];
                if(i == mid) m2 = nums2[r];

                r++;
            }
        }

        if(even) return (m1 + m2) / 2;
        else return m2;
    }
};