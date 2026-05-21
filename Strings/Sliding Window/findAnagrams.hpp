// Problem: Find all Anagrams in a string
// https://www.geeksforgeeks.org/dsa/check-whether-two-strings-are-anagram-of-each-other/


//BFS: TC: O((sLen - pLen + 1)(pLen)(log pLen)

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


