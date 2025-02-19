// https://leetcode.com/discuss/interview-question/6269115
// https://leetcode.com/discuss/interview-question/6298653
#include<bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;

int BFS(const vector<int>& v) {
    const int n = (int)v.size();
    vector mx(n, INT_MIN);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            mx[j] = max(mx[j], v[i]);
            ans += 1LL * mx[j] * (i - j + 1);
            ans %= mod;
        }
    return (int)ans;
}

int solve(const vector<int>& v) {
    const int n = (int)v.size();
    vector<long long> totals(n + 1), w(n + 1);
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        const int curr = v[i - 1];
        while (!stk.empty() && v[stk.top() - 1] <= curr)
            stk.pop();
        const int j = stk.empty() ? 0 : stk.top();
        w[i] = (w[j] + 1LL * curr * (i - j)) % mod;
        totals[i] = (totals[j] + w[j] * (i - j) + 1LL * curr * (i - j) * (i - j + 1) / 2) % mod;
        stk.push(i);
    }
    return (int)reduce(totals.begin(), totals.end(), 0LL, [&](auto& a, auto& b) {return (a + b) % mod;});
}

int main() {
     cout << solve({4, 2, 1, 2}) << endl; // 59
        cout << solve({4, 4}) << endl; // 16

    int n = 500, t = 1000, err = 0;
    mt19937 rng(time(nullptr));
    uniform_int_distribution d(1, 100'000);
    while (t--) {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(d(rng));
        auto ans1 = BFS(v);
        auto ans2 = solve(v);
        err += (ans1 != ans2);
    }
    cout << "errors = " << err << endl;
}