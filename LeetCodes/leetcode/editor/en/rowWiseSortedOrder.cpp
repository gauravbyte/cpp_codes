//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int median(vector<vector<int>> &mat) {
        // code here
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                minNum = min(minNum, mat[i][j]);
                maxNum = max(maxNum, mat[i][j]);
            }
        }
        int left = minNum;
        int right = maxNum;
        while(left < right) {
            int mid = left + (right - left) / 2;
            for(int i = 0; i < mat.size(); i++) {
                `

            }
        }

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends