// Problem: No. of Subarrays with Sum Divisible by K
// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Pattern: Prefix-Sum
//https://copilot.microsoft.com/shares/oPy3sNgo2aR2wGyroCwBJ


//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approach: Nested loop i and j to generate all subarrays, then calc sum, check divisibility and count

//Optimized: TC: O(N*logN) [ordered map], O(N*1) [Unordered map best and avg case], O(N*N) [Unorderd map worst case due to collisions]
// SC: O(N) map
//Approach: V.Imp 1.storing key as remainder wrt k for each prefix sum and value as freq of no. of times that remainder occurs
// 2. prefixSum[0] =1; first entry in map

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        mpp[0]=1;
        int prefixSum=0;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            prefixSum+= nums[i];
            int remainder = prefixSum % k;

            if(remainder < 0)
              remainder+=k;
            if(mpp.find(remainder) != mpp.end())
              cnt += mpp[remainder];

            if(mpp.find(remainder) == mpp.end())
            mpp[remainder]=1;
            else
            mpp[remainder]++;
        }
        return cnt;
    }
};
