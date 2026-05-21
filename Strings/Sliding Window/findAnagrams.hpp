// Problem: Find all Anagrams in a string
// https://www.geeksforgeeks.org/dsa/check-whether-two-strings-are-anagram-of-each-other/


//BFS: TC: O((sLen - pLen + 1)(pLen)(log pLen) N^2 witha n extra logN
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


//






