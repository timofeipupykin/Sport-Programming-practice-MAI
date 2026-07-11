#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
 
    for (int i = n; i > m; --i) {
        cout << i << " ";
    }

    for (int i = 1; i <= m; ++i) {
        cout << i << (i == m ? "" : " ");
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}