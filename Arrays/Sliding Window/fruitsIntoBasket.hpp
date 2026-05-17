//Problem: Fruits Into Basket
//https://leetcode.com/problems/fruit-into-baskets/
// “This is essentially the longest subarray with at most 2 distinct elements.
//Sliding window is the natural fit because we maintain a dynamic window that grows and shrinks based on the distinct count.”
//BFS: TC: O(N^2) 
//Nested Loop

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int ans=0;
        for(int l=0; l<n; l++)
        {
            unordered_map<int,int> freq;
            int cnt=0;
            for(int r=l; r<n; r++)
            {
                freq[fruits[r]]++;
                if(freq.size() > 2)
                {
                    break;
                }
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};


//Optimized: TC:O(2N) since both r and l touch each index only once. 
//Dynamic SW
//“I maintain a sliding window with at most 2 distinct fruit types. 
//Each time I add a fruit, if the window exceeds 2 types, I shrink from the left until valid again. 
//The window size gives the max fruits collected.”
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l=0,maxC =0;
        unordered_map<int,int> freq;
        for(int r=0; r<n; r++)
        {
            freq[fruits[r]]++;
            while(freq.size() > 2)
            {
                if (--freq[fruits[l]] == 0)
                  freq.erase(fruits[l]);
                l++;
            }
            maxC = max(maxC,r-l+1);
        }
        return maxC;
    }
};
