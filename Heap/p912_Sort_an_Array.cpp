// Problem: Sort an Array
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/sort-an-array/
// Topics: Heap Sort, down heapify
/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {
public:
    vector<int> nodes;
    void down_heapify(int idx) {
        while(1) {
            int minIdx = idx;
            
            int leftIdx = 2*idx+1;         
            int rightIdx = 2*idx+2;

            if(leftIdx < nodes.size() && nodes[leftIdx] < nodes[minIdx]) minIdx = leftIdx;
            if(rightIdx < nodes.size() && nodes[rightIdx] < nodes[minIdx]) minIdx = rightIdx;

            if(minIdx == idx) break;

            swap(nodes[minIdx], nodes[idx]);
            idx = minIdx;
        }
    }
    vector<int> heapSort() {
        int lastNonLeftNode = nodes.size()/2-1;
        vector<int> v;

        for(int i = lastNonLeftNode; i >= 0; i--) 
            down_heapify(i);

        int index = nodes.size();
        for(int i = 0; i < index; i++) {
            v.push_back(nodes[0]);
            swap(nodes[0], nodes[nodes.size()-1]);
            nodes.pop_back();
            down_heapify(0);
        }
        return v;
    }
    vector<int> sortArray(vector<int>& nums) {
        nodes = nums;
        return heapSort();
    }
};