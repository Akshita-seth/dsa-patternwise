// Problem: Length of longest Subarray with Sum Equals K 
// Link: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM
// Pattern: Prefix-Sum
//https://www.youtube.com/watch?v=frf7qxiN2qU

//Brute Force Soln: TC: O(n^2) SC: (1) 
//Approch: Nested loop, i for each element and 2 j loops- one for leftSum calc 0 to <i and another for rightSum calc i+1 to <n

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int maxi=0;
    for(int i=0; i<n; i++)
    {   long long sum=0;
        for(int j=i; j<n; j++)
        {
            sum+= a[j];
            if(sum == k)
            maxi=max(maxi, j-i+1);
            
        }
    }
    return maxi;
}

//Better soln for positives and zeors but optimal for negatives too.
//TC: O(N*logN) [ordered map], O(N*1) [Unordered map best and avg case], O(N*N) [Unorderd map worst case due to collisions]
// SC: O(N) map

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    unordered_map<long long, int> prefixSum;

    long long sum=0;
    int maxi=0;
    for(int i=0; i<n; i++)
    {
        sum+= a[i];
        if(sum == k)
         maxi= max(maxi, i+1);
        if(prefixSum.find(sum-k) != prefixSum.end())
         maxi = max(maxi, i - prefixSum[sum-k]);
        
        if(prefixSum.find(sum) == prefixSum.end())
         prefixSum[sum] = i;
    }
    return maxi;
}

//Optimized TC: O(n)
//Approach: Two Pointers in a greedy way. For positives only.

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int i=0, j=0;
    long long sum=a[0];
    int maxi=0;
    while(j<n)
    {
        while(i<=j && sum > k)
        {
            sum-= a[i];
            i++;
        }   
        if(sum == k)
           maxi= max(maxi, j-i+1);    
        j++;
        
        sum+= a[j];
    }
    return maxi;
}
