#include <iostream>
#include <algorithm>
using namespace std;

vector<int> countEleLessThanOrEqual(vector<int> arr1, vector<int>  arr2[], int m, int n) {
    sort(arr1.begin(), arr1.end());
    vector<int> ans;
    int j=0;
    for (int i = 0; i < n; i++) {
        int up = upper_bound(arr1.begin(), arr1.end(), arr2[i])-arr1.begin();
        int lb = lower_bound(arr1.begin(), arr1.end(), arr2[i])-arr1.begin();
        ans.push_back(up-lb);
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 7, 9};
    int arr2[] = {0, 1, 2, 1, 1, 4};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> ans;
    ans=countEleLessThanOrEqual(arr1, arr2, m, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}