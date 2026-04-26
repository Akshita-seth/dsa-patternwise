// Problem: Max sum subarray

//BFS

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxS = nums[0];
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum+=nums[j];
                maxS= max(maxS, sum);
            }
        }
        return maxS;
    }
};
