#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            int j = 0;
            while(j < n - i){
                temp.push_back(grid[i][j]);
                j++;
            }
            sort(temp.begin(), temp.end(),less<int>());
            j = 0;
            while(j < n - i){
                grid[i][j] = temp[j];
                j++;
            }
        }
        for(int j=1; j<n; j++) {
            vector<int> temp;
            int i = 0;
            while(i<n-j){
                temp.push_back(grid[i][j]);
                i++;
            }
            sort(temp.begin(), temp.end());
            i=0;
            while(i<n-i){
                grid[i][j] = temp[j];
                i++;
            }
        }
        return grid;

    }
};

int main() {
    vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};
    Solution s;
    s.sortMatrix(grid);
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;

    }
}