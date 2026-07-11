#include <bits/stdc++.h>
 
using namespace std;

bool check(int k, int n, const string& s) {
    vector<int> end_flip(n + 1, 0);
    int current_flips = 0;
 
    for (int i = 0; i < n; ++i) {
        current_flips ^= end_flip[i];
        
        int current_val = (s[i] - '0') ^ current_flips;
 
        if (current_val == 0) {
            if (i + k > n) {
                return false;
            }
            current_flips ^= 1;
            end_flip[i + k] ^= 1;
        }
    }
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    for (int k = n; k >= 1; --k) {
        if (check(k, n, s)) {
            cout << k << "\n";
            return;
        }
    }
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