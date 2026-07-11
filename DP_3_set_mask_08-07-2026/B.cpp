#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
 
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
 
    vector<int> dp((1 << n) * n, INF);
 
    dp[1 * n + 0] = 0;
 
    for (int mask = 1; mask < (1 << n); mask += 2) {
        for (int i = 0; i < n; ++i) {
            int current_dp = dp[mask * n + i];
            
            if (!(mask & (1 << i)) || current_dp == INF) continue;
 
            unsigned int unvisited = ((1u << n) - 1) ^ mask;
            
            while (unvisited > 0) {
                int j = __countr_zero(unvisited);
                
                int next_mask = mask | (1 << j);
                int& next_dp = dp[next_mask * n + j];
                
                next_dp = min(next_dp, current_dp + c[i][j]);
                
                unvisited &= (unvisited - 1);
            }
        }
    }
 
    int ans = INF;
    int full_mask = (1 << n) - 1;
    
    for (int i = 1; i < n; ++i) {
        if (dp[full_mask * n + i] != INF) {
            ans = min(ans, dp[full_mask * n + i] + c[i][0]);
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}
