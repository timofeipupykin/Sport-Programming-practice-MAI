#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
 
    vector<vector<int>> gold(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> gold[i][j];
        }
    }
 
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    dp[0][0] = gold[0][0];
 
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + gold[0][j];
    }
 
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + gold[i][0];
    }
 
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int max_prev = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            dp[i][j] = max_prev + gold[i][j];
        }
    }
 
    cout << dp[n - 1][m - 1] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}