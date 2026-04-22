// Problem: Valid Palindrome II
// Link: https://leetcode.com/problems/valid-palindrome-ii/description/
// Can be a palindrome by deleting at most one character
// Pattern: Two-pointer

// Optimized: TC: O(N) SC: O(N)
//At most one mismatch triggers a call to isPalin twice, each of which checks a substring in O(n) worst case.
//So overall, it’s still linear time, because the mismatch check happens only once, not repeatedly.

class Solution {
public:
    bool isPalin(string s, int start, int end )
    {
       while(start<end)
       {
        if(s[start] != s[end])
        return false;
        start++, end--;
       }
       return true;
    }
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j)
        {
            if(s[i] != s[j])
            {
              if(isPalin(s, i+1, j) || isPalin(s, i, j-1))
              return true;
              else
              return false;
            }
            i++, j--;
        }
        return true;
    }
};
