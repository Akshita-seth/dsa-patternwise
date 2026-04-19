// Problem: Product of Array except Itself
// Link: https://leetcode.com/problems/product-of-array-except-self/description/
// Pattern: Prefix-Sum
//

//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approach: Nested loop, i and j
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int i=0; i<n; i++)
        {
            int prod=1;
            for(int j=0; j<n; j++)
            {
                if(j!=i)
                {
                    prod*=nums[j];
                }
            }
            result.push_back(prod);
        }
        return result;
    }
};

//Optimized: Two Pass Solution - Just result vector and variable suffix(instead of prod)
// TC: O(n+n) SC: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,1);
       
        for(int i=1; i<n; i++)
        {
            result[i] = result[i-1] * nums[i-1];
        }
        int suffix=1;
        for(int i=n-1; i>=0; i--)
        {
            result[i] *= suffix;
            suffix*=nums[i];
        }
        return result;
    }
};

