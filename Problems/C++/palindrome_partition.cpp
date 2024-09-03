//Given a string s, partition s such that every substring  of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.

class Solution {
public:
    bool isPalindrome(string& s, int end, int length){
        int start = end - length;
        while (start <= end){
            if (s[start-1] != s[end-1])
                return false;
            start++;
            end--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++){
            dp[i] = i-1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < i; j++){
                if (isPalindrome(s, i, j))
                    dp[i] = min(dp[i], 1 + dp[i-j-1]);
            }
        }
        return dp[n];
    }
};