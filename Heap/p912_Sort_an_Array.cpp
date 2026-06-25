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
            int mnIdx = idx;
            int lIdx = idx*2+1,
                rIdx = idx*2+2;

            if(lIdx < nodes.size() && nodes[lIdx] < nodes[mnIdx]) mnIdx = lIdx;
            if(rIdx < nodes.size() && nodes[rIdx] < nodes[mnIdx]) mnIdx = rIdx;

            if(mnIdx == idx) break;

            swap(nodes[mnIdx], nodes[idx]);
            idx = mnIdx;
        }
    }

    int pop() {
        int mn = nodes[0];
        nodes[0] = nodes[nodes.size()-1];
        nodes.pop_back();
        down_heapify(0);
        return mn;
    }

    vector<int> minHeap() {
        vector<int> v;
        while(!nodes.empty()) v.push_back(pop());
        return v;
    }

    void arrToHeap(vector<int>& nums) {
        nodes = nums;

        int lastNonLeafNode = nums.size()/2-1;
        for(int i = lastNonLeafNode; i >= 0; i--) down_heapify(i);
    }

    vector<int> sortArray(vector<int>& nums) {
        arrToHeap(nums);
        return minHeap();
    }
};