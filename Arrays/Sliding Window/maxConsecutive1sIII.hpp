// Problem: Max Consecutive 1s III
//https://leetcode.com/problems/max-consecutive-ones-iii/
//https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1


//BFS TC: O(N^2)
// Nested Loop. Interview phrasing: “Check all subarrays, count zeros — too slow.”
// can give TLE

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen=0;

        for(int i=0; i<n; i++)
        {
          int flip=0, len=0;
          for(int j=i; j<n; j++)
          {
            if(nums[j] == 0) flip++;
            if(flip > k) break;
            len++;
          }
           maxLen = max(maxLen,len);  //instead of calculating len, j-i+1 can also be done.
        }
        return maxLen;
    }
};

// Better : O(N^2)>TC>O(N)
//Dynamic SW Interview phrasing: “Maintain a window with ≤ k zeros; expand and contract dynamically(greedily).
// TC is O(2N) bcz right pointer touches every index once and left pointer ttouches every index once only.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left = 0, zeros = 0, maxLen = 0;
        
        for(int right=0; right<n;  right++)
        {
            if(nums[right] == 0) zeros++;
          //we use while loop here, bcz we need to move the left pointer until the window becomes a valid one, i.e., with at most k zeros. 
            while(zeros > k) //shrinking
            {
                if(nums[left] == 0)  zeros--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

//Optimized: TC:O(N)
//Here we will not make the right pointer wait while the left pointer comes to a valid index. We will keep the right pointer moving.
// With or without maxi, both can be done
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi=0, left=0, zeros=0;
        for(int right=0; right<n; right++)
        {
            if(nums[right] == 0)
            zeros++;
            if(zeros > k)
            {
                if(nums[left] == 0) 
                zeros--;
                left++;
            }
            // maxi = max(maxi, right-left+1);
        }
        //return maxi;
        return n-left;
    }
};
