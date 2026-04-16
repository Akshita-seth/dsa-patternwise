// Problem: Two Sum II
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Pattern: Two-pointer

//Brute Force Soln: TC: O(n^2) SC: O(1)
//Approch: Nested loop i and j

//Better Soln: TC: O(n) SC: O(n)
//Approch: Hashmap

//Optimized: TC: O(n)[two pointer] + o(nlogn) [sorting]
//Approach: Two Pointer, Greedy way

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j,sum;
        int n = numbers.size();
        i = 0;
        j = n-1;
        while(i<j)
        {
            sum = numbers[i] + numbers[j];
            if(sum == target)
            return {i+1 , j+1};
            else if(sum > target)
            j--;
            else
            i++;
        }
        return {0,0};
    }
};