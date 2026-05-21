// Problem: Find all Anagrams in a string
// https://www.geeksforgeeks.org/dsa/check-whether-two-strings-are-anagram-of-each-other/
//https://www.youtube.com/watch?v=bK1z7nWoIwE
//Link: 


//Generating all substrings approach
//BFS: TC: O((sLen - pLen)(pLen)(log pLen) N^2 witha n extra logN
// Sorting and checking
//Gets TLE
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen=s.size();
        int pLen=p.size();
        vector<int> ans;
        sort(p.begin(), p.end());
        for(int i=0; i<=sLen-pLen; i++)
        {
            vector<char> q;
            for(int j=i; j<i+pLen; j++)
            {
               q.push_back(s[j]);
               if(q.size() == pLen)
               {
                 sort(q.begin(), q.end());
                 int k=0;
                  while(p[k] == q[k])
                   {
                     k++;
                      if(k==pLen)
                      {
                        ans.push_back(i);
                        break;
                      }
                   }
               }
            }
        }
        return ans;
    }
};

//Anotehr version of same TC above
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen=s.size();
        int pLen=p.size();
        vector<int> ans;
        sort(p.begin(), p.end());
        for(int i=0; i<=sLen-pLen; i++)
        {
            string q = "";
            for(int j=i; j<i+pLen; j++)
            {
               q += s[j];
               if(q.size() == pLen)
               {
                 sort(q.begin(), q.end());
                      if(q==p)
                        ans.push_back(i);
               }
            }
        }
        return ans;
    }
};

// Better than BFS/ Expected BFS: Freq counting and checking. Array o constant size 26.
// TC: O(N*M) N=sLen, M=pLen
// Acceptble soln but very slow
//if N: 10^4 order, M: 10^3 order 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen=s.size();
        int pLen=p.size();

        vector<int> ans;
        vector<int> pCount(26,0);

        for(char ch : p)    //10^3 = 1000 times run
          pCount[ch - 'a']++;
                         // 9000*1000 = 10^6 times => N^2 
        for(int i=0; i<=sLen-pLen; i++)  //10,000-1000=9000 times run
        {
            vector<int> sCount(26,0);
            for(int j=i; j<i+pLen; j++) //1000 times run i.e. pLen times
            {
                sCount[s[j]-'a']++;
            }
            if(pCount == sCount)
            ans.push_back(i);
        }
        return ans;
    }
};

//Optimized: SW and Map TC:O(N)
//SLIDING WINDOW APPROACH-> since substrings check needed
// r pointer character check in pMap, if present and freq>0, add in cMap and reduce count by 1. If at end of substring, count=0 => anagram substring found between l and r pointer 
// => add l index since start index is l of the valid substring but if substring length i.e. r-l+1 > pLen then shrink l before adding as start index
// r pointer=> increses freq in sMap and reduces count
// l pointer=> decreases freq in sMap and increases count
// for expansion of r or Shrinking of l => (pCount.find(s[r]) != pCount.end() && sCount[r] <= pCount[r]) needs to be true. 1st=> character present in the p map & 2nd=> that was a required character for anagram

// Optimized using SW and 2 Maps
//TC: O(2N) SC: O(

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pLen=p.size();
        int sLen=s.size();
        vector<int> ans;
        unordered_map<char,int> sCount;
        unordered_map<char,int> pCount;
        
        for(char ch: p)  
        pCount[ch]++;
        
        int l=0, count=pLen;
        for(int r=0; r<sLen; r++)
        {
            char right=s[r];
            //EXPANSION
            sCount[right]++;
            if(pCount.find(right) != pCount.end() && sCount[right] <= pCount[right])
                count--;
            //SHRINKING
            if(r-l+1 > pLen)
            {
                char left=s[l];
                if(pCount.find(left) != pCount.end() && sCount[left] <= pCount[left])
                    count++;

                sCount[left]--;
                l++;
            }
            if(count == 0)
            ans.push_back(l);
        }
        return ans;
    }
};


// SW & 1 Map





