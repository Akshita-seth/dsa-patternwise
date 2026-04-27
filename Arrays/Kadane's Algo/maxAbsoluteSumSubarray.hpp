// Probelm: Max absolute sum of subarray
//Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

//BFS: TC:O(N^2) Nested i and j

int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int maxAbs = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            maxAbs = max(maxAbs, abs(sum));
        }
    }
    return maxAbs;
}


// Optimized: TC: O(N)
// You don’t need to compute max(maxS, abs(minS)) inside the loop every iteration.
// Here’s why: maxS is tracking the maximum subarray sum so far (Kadane’s forward run).
// minS is tracking the minimum subarray sum so far (Kadane’s inverted run).
// Both are updated at each step, so by the time the loop finishes, they already represent the global best and worst subarrays.

//Loop starts at i = 0, You initialize currMax = nums[0], currMin = nums[0], etc.
// If you immediately run the loop from i = 0 again, that double‑counts the first element and messes up the Kadane transitions. The loop should start at i = 1.

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax=nums[0];
        int maxS=nums[0];
        int currMin=nums[0];
        int minS=nums[0];
        int maxFinal;

        for(int i=1; i<nums.size(); i++)
        {
            currMax = max(nums[i], currMax+nums[i]);
            maxS =  max(maxS, currMax);

            currMin = min(nums[i], currMin+nums[i]);
            minS = min(minS, currMin);
        }
        return max(maxS, abs(minS));
    }
};
