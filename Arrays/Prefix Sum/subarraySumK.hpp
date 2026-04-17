// Problem: Subarray Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Pattern: Prefix-Sum
//

//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approch: Nested loop, i for each element and 2 j loops- one for leftSum calc 0 to <i and another for rightSum calc i+1 to <n

//Optimized TC: O(n)
//Approach: USe total sum to calc right sum without any loop



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        mpp[0]=1;
        int preSum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            preSum +=nums[i];
            int remove=preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};