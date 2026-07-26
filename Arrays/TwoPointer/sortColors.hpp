// Problem: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/description/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s

// BFS: Count number of 0s, 1s and 2s then overwrite in the array - Two pass solution
// TC: O(n)  SC:O(1)

void sortColors(vector<int>& nums) {
        int z=0, o=0, t=0;
        for(int &n:nums)
        {
            if(n == 0) z++;
            else if(n == 1) o++;
            else if(n == 2) t++;
        }
        int i = 0;
        while (z--) nums[i++] = 0;
        while (o--) nums[i++] = 1;
        while (t--) nums[i++] = 2;
    }

//Optimized: DUTCH NATIONAL FLAG ALGORITHM - One pass solution
// We maintain three pointers: low → boundary for 0s, mid → current element being checked, high → boundary for 2s
// Instead of counting or sorting, DNF partitions the array into three regions dynamically:
// Left side → all 0s
// Middle → all 1s
// Right side → all 2s
// TC: O(n) SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++; mid++;
            }
            else if(nums[mid]==1)
            mid++;
            else
            {
              swap(nums[mid],nums[high]);
              high--;
            }
        }
        
    }
};
