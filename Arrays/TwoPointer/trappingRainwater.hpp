// Problem: Trapping Rainwater
// Link: https://leetcode.com/problems/trapping-rain-water/description/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/trapping-rainwater

// BFS: Taking current element i, callc maxLeft and maxRight each time with j loop, then calc total water: total += min(maxLeft, maxRight) - height[i];
// TC: O(n^2)  SC:O(1)

//Optimized: 
// TC: O(n) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int left = 0, right = n-1;
        int maxLeft=0, maxRight=0;
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= maxLeft)
                maxLeft = height[left];
                else
                totalWater+= maxLeft - height[left];

                left++;
            }
            else
            {
                if(height[right] >= maxRight)
                maxRight = height[right];
                else
                totalWater+= maxRight - height[right];

                right--;
            }
        }
        return totalWater;
    }
};