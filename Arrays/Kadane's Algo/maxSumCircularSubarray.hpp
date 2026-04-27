// Problem: Max Sum Circular Subarray
// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/
// https://youtu.be/fxT9KjakYPM?si=SGCLQnlGDawW0ELz

// BFS: Nested loop TC: O(N^2)

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int len = 0; len < n; len++) {
            sum += nums[(i + len) % n];   // wrap around using modulo
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

//Optimized using Kadane's  TC: O(N)
//either maxFinal is the largest or (totalSum - minSum). BCZ: total - minsum = maxsum

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=nums[0];
        int maxS=nums[0];

        int currMin=nums[0];
        int minS=nums[0];

        int maxFinal=nums[0];
        int totalSum=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            totalSum += nums[i];

            currMax = max(nums[i], currMax + nums[i]);
            maxS = max(maxS, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minS = min(minS, currMin);

            maxFinal = max(maxFinal, maxS);
        }
        if(maxFinal < 0) 
          return maxFinal;

        return max(maxFinal, totalSum - minS);
        
    }
};
