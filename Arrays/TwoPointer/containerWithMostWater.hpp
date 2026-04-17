// Problem: Container with Most Water
// Link: https://leetcode.com/problems/container-with-most-water/description/
// Pattern: Two-pointer

// BFS: Nested loop, try all possible pairs
// TC: O(n^2)  SC:O(1)

//Optimized: calc are by two pointers and move the pointer pointing the shorter line
// TC: O(n) SC: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
       int i=0, j=n-1; 
       int waterMax = 0;
       while(i<j)
       {
         waterMax = max(waterMax, (j-i)* min(height[i], height[j]));
         if(height[i] < height[j]) i++;
         else j--;
       }
       return waterMax;
    }
};