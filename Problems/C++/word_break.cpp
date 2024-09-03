'''*Given a string s and a dictionary of strings wordDict, add spaces in s to construct 
a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word. '''

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.size(),vector<string>{});
        for (int i = 0; i < s.size(); i++){
            for(string word: wordDict){
                int n = word.size();
                if (i < n-1)
                    continue;
                if (i == n-1 || dp[i - n].size() > 0){
                    if (s.substr(i-n+1,n) == word){
                        if (i-n+1 == 0)
                            dp[i].push_back(word);
                        else{
                            for (string w: dp[i-n]){
                                dp[i].push_back(w + " " + word);
                            }
                        }
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};