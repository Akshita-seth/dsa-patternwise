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

//without swap fn
void reverseString(string &s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        // Manual swap using a temp variable
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}
