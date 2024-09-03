/*

Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing subsequence is 3, 10, 20

*/

#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Function to compute LIS ending with 
// index i using memoization
int lisEndAtI(int arr[], int i, int dp[])
{
    // Base case
    if (i == 0)
        return 1;

    // Check if the result is already computed
    if (dp[i] != -1)
        return dp[i];

    // Consider all elements on the left of i,
    // recursively compute LISs ending with
    // them and consider the largest
    int mx = 1;
    for (int prev = 0; prev < i; prev++)
        if (arr[prev] < arr[i])
            mx = max(mx, lisEndAtI(arr, prev, dp) + 1);

    // Store the result in the dp array
    dp[i] = mx;
    return dp[i];
}

int lis(int arr[], int n)
{
    int dp[n];
  
    // Initialize memoization array with -1
    memset(dp, -1, sizeof(dp));
  
    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, lisEndAtI(arr, i, dp));
    return res;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
    return 0;
}