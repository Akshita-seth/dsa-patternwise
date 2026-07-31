// Problem: Max Consecutive 1s II => at most one 0 flip allowed
// https://www.geeksforgeeks.org/dsa/max-number-of-one-ii/

// BFS TC: O(N^2)
//Interview phrasing: “Naively, I brute force by flipping each zero and checking the streak.”
int findMaxConsecutiveOnesII_Brute(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int flips = 0, len = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == 0) flips++;
            if (flips > 1) break;
            len++;
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}

//Better TC: O(N) SC: O(N)
//Interview phrasing: “I use prefix/suffix arrays to connect runs of 1s across a flipped zero.”

int findMaxConsecutiveOnesII_Prefix(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n,0), right(n,0);

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) left[i] = (i>0 ? left[i-1] : 0) + 1;
    }
    for (int i = n-1; i >= 0; i--) {
        if (nums[i] == 1) right[i] = (i<n-1 ? right[i+1] : 0) + 1;
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            int len = (i>0 ? left[i-1] : 0) + 1 + (i<n-1 ? right[i+1] : 0);
            maxLen = max(maxLen, len);
        }
    }
    return maxLen == 0 ? n : maxLen; // handle all-ones case
}



// Optimized solutions [Give in interviews]
// TC: O(N) SC: O(1)

// 1. GREEDY Approach
//Interview phrasing: “I track both streaks in one pass, achieving linear time and constant space.”
#include <bits/stdc++.h>
using namespace std;

// Computes the maximum consecutive 1s after flipping at most one 0
int maxConsecutiveOne(vector<int> arr, int N)
{
    int ones = 0;
    int ones_and_zero = 0;
    int ret = 0;

    for (int num : arr) {
        // Extend current streak of ones
        if (num == 1) {
            ++ones;
            ++ones_and_zero;
        }
        else {
            // Flip this zero and connect previous streak
            ones_and_zero = ones + 1;
            ones = 0;
        }

        ret = max(ret, ones_and_zero);
    }

    return ret;
}

// 2. Sliding Window Approach
// Maintain a window [left, right] that contains at most one zero.
// Expand right as you traverse.
// If the window has more than one zero, shrink left until only one zero remains.
// Track the maximum window length

int longestOnes(vector<int>& nums) {
    int left = 0, zeroCount = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeroCount++; 
        while (zeroCount > 1) { // shrinking
            if (nums[left] == 0) zeroCount--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}


