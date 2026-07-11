#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    if (!(cin >> n >> m)) return 0;
 
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[1][1] = a[1][1];
    
    int max_gold = dp[1][1];
 
    int di[] = {2, 2, 1, -1};
    int dj[] = {-1, 1, 2, 2};
 
    for (int s = 2; s <= n + m; ++s) {
        int min_i = max(1, s - m);
        int max_i = min(n, s - 1);
        
        for (int i = min_i; i <= max_i; ++i) {
            int j = s - i;
            
            if (dp[i][j] == -1) continue;
 
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
 
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + a[ni][nj]);
                    max_gold = max(max_gold, dp[ni][nj]);
                }
            }
        }
    }
 
    cout << max_gold << "\n";
 
    return 0;
}
