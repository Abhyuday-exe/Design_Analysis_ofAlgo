
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChain(int p[], int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j]
                         + p[i-1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n+1];

    cout << "Enter dimensions array: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Minimum number of multiplications: "
         << matrixChain(p, n+1) << endl;

    return 0;
}

