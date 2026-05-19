//Problem: Subarrays With K Distinct
//https://leetcode.com/problems/subarrays-with-k-different-integers/

//BFS: TC:O(N^2) SC: O(K)
// Nsted Loop using map

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;

        for(int i=0; i<n; i++)
        {
            unordered_map<int,int> freq; 
            for(int j=i; j<n; j++)
            {
                freq[nums[j]]++;
                if(freq.size() == k)
                   c++;
                else if(freq.size() > k)
                break;
            }
        }
        return c;
    }
};


//Optimized: 
//

