// Problem: Max Sum Subarray of length K

// Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
//BFS: TC: O((n-k)*k)  SC: O(1)
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maxS=0;
        for(int i=0; i<= n-k; i++)
        {
            int sum=0;
            for(int j=i; j<i+k; j++)
            {
                sum += arr[j];
            }
            maxS = max(maxS, sum);
        }
        return maxS;
    }
};

// Optimizedd: TC: O(k + n - k)= O(n)

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int windowSum = 0;
        
        for(int i=0; i<k; i++)  //O(k)
         windowSum += arr[i];
        
        int maxS = windowSum;
        
        for(int j=k; j<n; j++)  // O(n-k)
        {
            windowSum += arr[j];
            windowSum -= arr[j-k];
            
            maxS = max(maxS, windowSum);
        }
        return maxS;
    }
};

// If a distinct subarray is asked
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

// BFS: TC: O((n-k)*k) SC: O(k)

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        long long maxS = 0;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int,int> freq;
            long long sum = 0;
            bool distinct = true;

            for (int j = i; j < i + k; j++) {
                freq[arr[j]]++;
                sum += arr[j];
                if (freq[arr[j]] > 1) {
                    distinct = false; // duplicate found
                }
            }

            if (distinct) {
                maxS = max(maxS, sum);
            }
        }
        return maxS;
    }
};

// Optimized using Sliding Window
// TC: O(N) SC: O(K)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        long long windowSum = 0;
        unordered_map<int,int> freq;

        for(int i=0; i<k; i++)
        {
             windowSum += nums[i];
             freq[nums[i]]++;
        }
        long long maxS = (freq.size() == k ? windowSum : 0);

        for(int j=k; j<n; j++)
        {
            //Add new element
            windowSum += nums[j];
            freq[nums[j]]++;
            //Remove old element
            windowSum -= nums[j-k];
            if(--freq[nums[j-k]] == 0)
              freq.erase(nums[j-k]);
            //check distinctness
            if(freq.size() == k)
              maxS = max(maxS, windowSum);
        }
        return maxS;
    }
};


//DND
//if(freq[nums[j-k]] == 1)
  //  freq.erase(nums[j-k]);
//This works, but only if the outgoing element’s count is exactly 1. 
//If it’s greater than 1, you’re not decrementing it, so duplicates remain incorrectly counted. That’s why the solution isn’t being accepted.
