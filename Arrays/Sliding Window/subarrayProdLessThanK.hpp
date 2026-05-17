// Problem: Subarrya Product Less than k
// https://leetcode.com/problems/subarray-product-less-than-k/description/

//BFS: TC: O(N^2)
//Generate all subarrays using nested loop
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      if(k <= 1) return 0; // very imp line HANdLING EDGE CASE IF K=0 OR 1
        int n = nums.size();
        int c = 0;
        for(int i=0; i<n; i++)
        {
            int prod = 1;
            for(int j=i; j<n; j++)
            {
                prod *= nums[j];
                if (prod < k) c++;    // check inside inner loop
                else break;        // no need to continue if product already too large
            }
        }
        return c;
    }
};

// Optimized: YC: O(N) right pointer touches every index once, and if wort casebthen 2N TC since left also touches.
//Basically uisng => No. of subarrays b/w two indexes l & r is r-l+1 i.e. no. of subarrays ending at r.
//“Since all elements are positive, the smallest product we can form is 1. 
//If k ≤ 1, no subarray can satisfy product < k, so we return 0 immediately. This avoids edge‑case bugs and unnecessary computation.”
// This is a classic example of handling edge cases up front 

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0; // very imp line (significance above)
        int n = nums.size();
        int left=0, c=0;
        long long prod=1;
        for(int right=0; right<n; right++)
        {
            prod *= nums[right];
            while(prod >= k)
            {
                prod /= nums[left];
                left++;
            }
            c += right-left+1;  // all subarrays ending at right
        }
        return c;
    }
};
