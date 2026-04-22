// Problem: Reverse A String
// Link: https://leetcode.com/problems/reverse-string/
// Pattern: Two-pointer

// Optimized: TC: O(N) SC: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
