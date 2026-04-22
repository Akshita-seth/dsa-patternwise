// Problem: Count Palindromic Substrings
// Link: https://leetcode.com/problems/palindromic-substrings/
// Pattern: Two-pointer

//BFS: TC:O(N^3) SC:O{N^2)
//The number of substrings in a string of length n is n(n+1)/2 => O(N^2)
//BFS may enqueue nearly all of them, so the queue can hold O(N^2) states. That’s why space complexity is quadratic.
   
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        queue<pair<int,int>> q; // store substring boundaries [l,r]

        // initialize with all single characters (trivial palindromes)
        for(int i=0; i<n; i++) {
            q.push({i,i});
            cnt++;
        }

        // also initialize with all pairs of equal adjacent chars
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                q.push({i,i+1});
                cnt++;
            }
        }

        // BFS expansion
        while(!q.empty()) {
            auto [l,r] = q.front(); // shorthand for=>  pair<int,int> p = q.front(); int l = p.first; int r = p.second;
            q.pop();
            // try to expand outward
            if(l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
                q.push({l-1,r+1});
                cnt++;
            }
        }

        return cnt;
    }
};



//Optimized: TC: O(N^2) SC: O(1) 
// Expand from centre approach
//
// technically=> helper palin/expand functions are of O(N/2) 

class Solution {
private:
    int expand(string s, int left, int right)
    {
        int cnt=0;
        while(left>=0 && right<s.size() && s[left] == s[right])
        {
            cnt++; // each valid expansion is a palindrome
            left--;
            right++;
        }
        return cnt;
    }

public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            cnt += expand(s,i,i);
            cnt += expand(s,i,i+1);
        }
        return cnt;
    }
};
