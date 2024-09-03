
#include <stdio.h>
#include <string.h>

int lengthOfLIS(int* nums) {
    int len = sizeof(nums) / sizeof(int);
    int max_len = 1;
    int dp[len+1];

    // int* dp = (int*)malloc(sizeof(int) * len);

    for (int i=len -2; i>=0 ; --i) {
        for (int j=i+1; j<len ; ++j) 
            if(nums[i] < nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        
        max_len = max(max_len,dp[i]);
    }
    return max_len;
}


// 더 빠른 C++인데 알아서.. lower_bound 가 없음 C는
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> arr;
		vector<int>::iterator it;
		for (int i=0; i<nums.size() ; ++i) {
			it = lower_bound(arr.begin(), arr.end(), nums[i] );
			if (it == arr.end())
				arr.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return arr.size();
    }
};
*/