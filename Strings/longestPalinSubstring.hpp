// Problem: Longest Palindromic String
// Link: https://leetcode.com/problems/longest-palindromic-substring/
// Pattern: Two-pointer
//https://www.youtube.com/watch?v=5MS14_6rSa8

//BFS: SHRINKING approach in isPalin 
//TC: O(N^3) i, j and isPalin
// SC: O(N) temp variable auxiliary space used.

  class Solution {
private:
    bool isPalin(string newS)
    {
        int start=0,end=newS.size()-1;
        while(start<=end)
        {
            if(newS[start++]!=newS[end--])
            return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int maxSize=0;
        string maxS;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string temp=s.substr(i,j-i+1);
                if(isPalin(temp))
                {
                    if(temp.size()>maxSize)
                    {
                        maxSize=temp.size();
                        maxS=temp;
                    }
                }
            }
        }
        return maxS;
    }
};

//Optimized by Two pointer-> EXPAND around the centre (done by helper fn),->start and end used to read the string, -> odd palin ex aba and even palin ex abba
//-> length returned by helper fn is right-left-1 => In the expand function, the loop stops after left and right go one step too far (either out of bounds or mismatched).
//At that point: left has been decremented one step past the valid palindrome boundary and right has been incremented one step past the valid palindrome boundary.
//So the actual palindrome length is not (right - left + 1) but rather (right - 1) - (left + 1) + 1, which simplifies to right - left - 1.

// TC: O(N^2) SC: O(1)

class Solution {
private: 
    int expand(string s, int left, int right)
    {
        while(left>=0 && right<s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0, end=0;
        
        for(int i=0; i<n; i++)
        {
            int oddLen = expand(s,i,i);
            int evenLen = expand(s,i,i+1);
            int len = max(oddLen, evenLen);

            if(len > end-start)
            {
                start = i-(len-1)/2;
                end = i+(len/2);
            }
        }
        return s.substr(start, end-start+1);
    }
};



