//Problem: Min Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

//BFS: TC: O(N^2)
//Nested loop

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum >= target)
                {
                    //int len= j-i+1; //even if len used, initialise it here
                    ans = min(ans, j-i+1); 
                    break;
                }
            }
        }
        if(ans == INT_MAX) return 0; //counter if sum never becomes >= target
        return ans;
    }
};


//Optimized: TC: O(2N)
//Dynamic SW
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0, ans=INT_MAX, sum=0;

        for(int r=0; r<n; r++)
        {
            sum += nums[r]; //EXPANDING
            while(sum >= target)
            {
                ans = min(ans, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};
