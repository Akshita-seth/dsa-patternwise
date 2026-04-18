// Problem: Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index/
// Pattern: Prefix-Sum
//https://www.youtube.com/watch?v=WOivGAlWxlM&list=PLvNVexrplJJzc0FYDK1M7feNLJVSCV-cL

//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approch: Nested loop, i for each element and 2 j loops- one for leftSum calc 0 to <i and another for rightSum calc i+1 to <n

//Optimized TC: O(n+n) = O(n)
//Approach: USe total sum to calc right sum without any loop

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum=0;
        for(int i=0; i<n; i++)
          totalSum += nums[i];
        
         int leftSum=0;
        for(int i=0; i<n; i++)
        {
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum)
            return i;
            leftSum += nums[i];
        }
        return -1;
    }
};