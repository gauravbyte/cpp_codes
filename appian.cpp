#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> codes(n);
    for(int i=0;i<n;i++)
        cin >> codes[i];
    int m;
    cin >> m;
    map<int, int> mp;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    // vector<int> ans = getError
}