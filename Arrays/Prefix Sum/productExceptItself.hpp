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


//Optimized TC: O(n+n) = O(n)  SC: O(n+n)
//Approach: Two Pass Solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        vector<int> result(n);
        prefix[0] = 1;
       
        int prod=1;
        for(int i=0; i<n-1; i++)
        {
            prod*=nums[i];
            prefix[i+1]=prod;
        }
        prod=1;
        for(int i=n-1; i>=0; i--)
        {
            result[i] = prod*prefix[i];
            prod*=nums[i];
        }
        return result;
    }
};

//Optimized to One Pass Solution - Just result vector and variable suffix(instead of prod)
// TC: O(n) SC: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        result[0] = 1;
       
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

