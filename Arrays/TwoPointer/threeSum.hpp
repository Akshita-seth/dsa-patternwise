// Problem: Three Sum
// Link: https://leetcode.com/problems/3sum/description/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero


//BFS: Three Nested Loops and set data structure to prevent duplicates
// TC: O(n^3) * O(log(no. of triplets)) sice insertion in set is logN as it is unique   
// SC: O(2*n) for set and temp 

// Better: Hashset use to find third number
// TC: O(N2 * log(no. of unique triplets))
// SC : O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and
// a list to store the triplets and extra O(N) for storing the array elements in another set.


// Optimized: 
// TC: O(NlogN)+O(N2) sorting + TwoPointer * i loop

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; //avoiding duplicates (substitutes using set data structure)
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while(j<k && nums[j]==nums[j-1]) j++;  //avoiding duplicates (substitutes using set data structure)
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};