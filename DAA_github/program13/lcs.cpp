
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LCS(string a, string b) {
    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    // Find the LCS string
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Length of LCS: " << dp[m][n] << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;
}

int main() {
    string a, b;

    cout << "Enter first string: ";
    cin >> a;

    cout << "Enter second string: ";
    cin >> b;

    LCS(a, b);

    return 0;
}
