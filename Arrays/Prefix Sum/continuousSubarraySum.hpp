// Problem: Array has a GOOD Subarray or not
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Pattern: Prefix-Sum
//https://copilot.microsoft.com/shares/JtXNRTd2RgagbZCByVGiC


//BFS: TC: O(n^2) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n-1; i++)
        {
            int sum=nums[i];
            for(int j=i+1; j<n; j++)
            {
                sum+= nums[j];
                if(sum%k == 0)
                return true;
            }
        }
        return false;
    }
};


//Optimized: TC: O(n) SC:O(n)
// For k == 0, only check if any subarray of length ≥ 2 has sum = 0.

// For general k, use remainder map with {0:-1} to catch subarrays starting at index 0.

// The map ensures we detect when two prefix sums share the same remainder, meaning the subarray between them is divisible by k.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0]=-1;
        int prefixSum=0;

        for(int i=0; i<nums.size(); i++)
        {
            prefixSum+=nums[i];
            int remainder = (k==0 ? prefixSum : prefixSum%k);

            if(mpp.find(remainder) != mpp.end())
            {
                if(i - mpp[remainder] >=2)
                return true;
            }
            else
            mpp[remainder] = i;
        }
        return false;
    }
};
