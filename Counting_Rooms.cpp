// Time limit: 1.00 s Memory limit: 512 MB
// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m
//  squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

// Input

// The first input line has two integers n
//  and m
// : the height and width of the map.

// Then there are n
//  lines of m
//  characters describing the map. Each character is either . (floor) or # (wall).

// Output

// Print one integer: the number of rooms.

// Constraints
// 1≤n,m≤1000

// Example

// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3

#include<bits/stdc++.h>
using namespace std;
int n,m;
void dfs(vector<vector<char> > &arr,int r,int c){
    if(r<0 || r>=n || c<0 || c>=m){
        return;
    }
    if(arr[r][c ]=='#'){
        return;
    }
    arr[r][c]='#';
    

    dfs(arr,r+1,c);
    dfs(arr,r,c+1);
    dfs(arr,r-1,c);
    dfs(arr,r,c-1);
}
int main()
{
    cin>>n>>m;
    vector<vector<char> > arr(n,vector<char>(m,'0'));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='.'){
                dfs(arr,i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

