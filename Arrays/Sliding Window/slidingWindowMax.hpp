//Problem" Sliding Window Maximum
//  https://leetcode.com/problems/sliding-window-maximum/
// https://www.youtube.com/watch?v=e8iJPXS64MY&list=PLvNVexrplJJyQTJ7a6sx3MzZjq1cR2geB&index=10

//BFS: TC: O((n-k)*k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0; i<=n-k; i++)
        {
            int maxi=nums[i];
            for(int j=i; j<i+k; j++)
            {
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

// Better: every insertion and deletion will cost us log k time complexity
// Use heap data structure of k size as the window


//Optimized: TC: O(N) [worst case O(2N)]  SC: O(K) [both best and worst]
// Dequeue. 
// If we encounter a larger value after a smaller value => remove the smaller.
// If we encounter a smaller value after a larger value => keep the smaller.
//Until the present value in the dq is smaller than the upcoming value from arr, we will pop. => while condition and not if
//We store indices in the deque, and for values of nums we access using the deque value


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of useful elements
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // 1. Remove indices out of current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // 2. Remove smaller elements (they’ll never be max)
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3. Add current element index
            dq.push_back(i);

            // 4. Record max once window size reached
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
