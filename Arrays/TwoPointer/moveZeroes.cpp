// Problem: Move Zeroes To The End
// Link: https://leetcode.com/problems/move-zeroes/
// Pattern: Two-pointer

//Brute Force Soln: TC: O(n) SC: (n) 
//Approch: Another array to store non-zeroes then copying 

//optimized TC: O(n)
 class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int j = -1;
      int n = nums.size();
      for(int i=0; i<n; i++)
      {
        if(nums[i] == 0)
        { 
           j = i;
           break;
        }
      }
      if(j == -1) return;

      for(int i = j+1 ; i<n; i++)
      {
        if(nums[i] != 0)
        {
          swap(nums[i], nums[j]);
          j++;
        }
      }
    }
};