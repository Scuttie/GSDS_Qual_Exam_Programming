#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int x, int y);

// Function to find length of Longest Common Substring for S1[0..m-1], S2[0..n-1]
int longest_common_substring(const char *S1, const char *S2) {
    int m = strlen(S1);
    int n = strlen(S2);

    // Initializing a matrix of size (m+1)*(n+1)
    int dp[m + 1][n + 1];
    int max_length = 0; // To store length of the longest common substring

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_length = max(max_length, dp[i][j]);
            }
            else {
                dp[i][j] = 0; // Substrings end here, so reset to 0
            }
        }
    }
   
    return max_length;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    const char *S1 = "ABCXYZ";
    const char *S2 = "XYZABC";
    printf("Length of Longest Common Substring is %d\n", longest_common_substring(S1, S2));

    return 0;
}
