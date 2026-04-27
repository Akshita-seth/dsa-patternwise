// Problem: Maximum subarray product
// Link: https://leetcode.com/problems/maximum-product-subarray/

//BFS: TC:O(N^2) Nested ia nd j loop

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxP=nums[0];
      
        for(int i=0; i<n; i++)
        {
            int product = 1;
            for(int j=i; j<n; j++)
            {
                product *= nums[j];
                maxP = max(maxP, product);
            }
        }
        return maxP;
    }
};

// Optimized:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1,suff=1;
        int maxP=INT_MIN;
        for(int i=0;i<n;i++){
           if(pre==0) pre=1;
           if(suff==0) suff=1;
           pre=pre*nums[i];
           suff=suff*nums[n-1-i];
           maxP=max(maxP,max(pre,suff));
            }
            return maxP;

    }
};


// Optimized using Kadane's

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxEndingHere, minEndingHere);

            maxEndingHere = max(nums[i], maxEndingHere * nums[i]);
            minEndingHere = min(nums[i], minEndingHere * nums[i]);

            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};
