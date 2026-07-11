#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    long long n;
    cin >> n;
 
    const int LIMIT = 200000;
    std::vector<bool> sieve(LIMIT + 1, true);
    std::vector<long long> p;
    for (int i = 2; i <= LIMIT; i++) {
        if (sieve[i]) {
            p.push_back(i);
            for (int j = 2 * i; j <= LIMIT; j += i) sieve[j] = false;
        }
    }
    
    for (int i = 1; i <= n; i++) {
            long long left  = (i >= 2)     ? p[i - 2] : 1;
            long long right = (i <= n - 1) ? p[i - 1] : 1;
            std::cout << left * right << " ";
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
