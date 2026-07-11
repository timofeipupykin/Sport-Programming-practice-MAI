#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> build_suffix_array(string s) {
    s += '$';
    int n = s.size();
    const int alphabet = 256;
    
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
 
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
 
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }
 
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
 
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
 
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev) classes++;
            cn[p[i]] = classes - 1;
        }
        c = cn;
    }
 
    p.erase(p.begin());
    return p;
}
 
vector<int> build_lcp(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n, 0);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
 
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) { k = 0; continue; }
        int j = sa[rank[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k > 0) k--;
    }
    return lcp;
}
 
void solve() {
    string str;
    if (!(cin >> str)) return;
    int n = str.size();
 
    vector<int> sa = build_suffix_array(str);
    vector<int> lcp = build_lcp(str, sa);
 
    long long total_distinct_substrings = 0;
    for (int i = 0; i < n; i++) {
        total_distinct_substrings += (n - sa[i]) - lcp[i];
    }
    cout << total_distinct_substrings << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
