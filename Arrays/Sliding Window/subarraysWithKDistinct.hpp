//Problem: Subarrays With K Distinct
//https://leetcode.com/problems/subarrays-with-k-different-integers/

//BFS: TC:O(N^2) SC: O(K)
// Nsted Loop using map

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
        unordered_map<int,int> freq;
        for(int i=0; i<n; i++)
        { 
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


//Optimized: TC: O(N) only r touches each index and worst case O(2N) since both la dn r will touch each indes i.e. if all digits distinct
//Formulas used: 1. [exactlyK(nums,k) = atMostK(nums,k) - atMostK(nums,k-1)] 2. No. of subarrays ending at index r => r-l+1
//atMostK(nums,k) => Gives no. of subarrays with <= k distinct digits
//atMostK(nums,k-1) => Gives no. of subarrays with <= (k-1) distinct digits
// We need no. of subarrays with exactly k distinct digits, hence, [exactlyK(nums,k) = atMostK(nums,k) - atMostK(nums,k-1)]

class Solution {
public:
    int atMostK(vector<int>& nums, int k)
    {
        int n=nums.size();
        int l=0,c=0 ;
        unordered_map<int,int> freq;
        for(int r=0; r<n; r++)
        {
            freq[nums[r]]++;   //EXPANDING
    
            while(freq.size() > k)  //SHRINKING
            {
                if(--freq[nums[l]] == 0)
                freq.erase(nums[l]);
                l++;
            }
            c += (r-l+1); //counting subarrays with distinct digits < & =k when tis is called atMostK(nums,k)
        }
        return c;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k) - atMostK(nums,k-1);  
    } 
};

