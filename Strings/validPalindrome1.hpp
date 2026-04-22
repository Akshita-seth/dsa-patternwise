// Problem: Valid Palindrome 1
// Link: https://leetcode.com/problems/valid-palindrome/description/
// Pattern: Two-pointer

//If just basic plaindrome check: newS=reverse of string, then check each char
// SC: O(N) TC: O(N)

// Optimized: TC: O(N) SC: O(N)

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j)
        {
          //ignoring spaces and special characters
         while(i<j && !isalnum(s[i])) i++;
         while(i<j && !isalnum(s[j])) j--;
           

            if(tolower(s[i]) != tolower(s[j]))
            return false;
            
            i++, j--;
        }
        return true;
    }
};
