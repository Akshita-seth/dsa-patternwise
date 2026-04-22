// Problem: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/
// Pattern: Sliding Window

//Optimized Solution: TC: O(N) SC: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                c++;
                maxi=max(c,maxi);
            }
            else
            c=0;
        }
        return maxi;
    }
};
