// Problem: Prime Subset Selection I
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/prime-subset-selection-i/
// Topics: Prime numbers, Loop & indexing logic
/*
You are given two integers n and s.

Consider all prime numbers less than or equal to n. Select some of these primes such that:

The sum of the selected primes is less than or equal to s.
The number of selected primes is maximized.
Each prime can be selected at most once.
Return an integer array containing the selected primes in increasing order. If multiple optimal selections exist, return any of them.

If no prime can be selected, return an empty array.

 

Example 1:

Input: n = 7, s = 20

Output: [2,3,5,7]

Explanation:

The prime numbers less than or equal to n = 7 are 2, 3, 5, and 7.
The sum of all these primes is 2 + 3 + 5 + 7 = 17, which is less than or equal to s = 20.
Thus, the answer is [2, 3, 5, 7].
Example 2:

Input: n = 15, s = 15

Output: [3,5,7]

Explanation:

The prime numbers less than or equal to n = 15 are 2, 3, 5, 7, 11, and 13.
One possible selection is [3, 5, 7], whose sum is 3 + 5 + 7 = 15.
The four smallest available primes have sum 2 + 3 + 5 + 7 = 17, which exceeds s = 15. Therefore, selecting four or more primes is impossible, and the maximum number of selected primes is three.
Thus, [3, 5, 7] is one possible answer. Other valid answers include [2, 3, 5], [2, 3, 7], and [2, 5, 7].
Example 3:

Input: n = 5, s = 1

Output: []

Explanation:

The smallest prime number is 2, which is greater than s = 1.
Thus, no prime can be selected, so the answer is an empty array.
 

Constraints:

1 <= n <= 106
1 <= s <= 109
*/
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        long long sum = 0;
       for(int i = 2; i <= n; i++) {
           bool flag = true;
           for(int j = 2; j * j <= i; j++) {
                if(i % j == 0) {
                    flag = false;
                    break;
                } 
           }
           if(flag) {
               sum += i;
               if(sum > s) break;
               else ans.push_back(i);  
           }
       }
        return ans;
    }
};