#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector<pair<int,int> > monsters;
    int start_row=-1,start_col=-1;

    vector<vector<char> > grid(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M'){
                monsters.push_back({i,j});
            }
            else if(grid[i][j]=='A'){
                start_row=i;
                start_col=j;
            }
        }
    }
    queue<pair<int,pair<int,int> > > q;

    //1 for the player and 0 for the monster
    for(auto monster:monsters){
        q.push({0,monster});
    }
    q.push({1,{start_row,start_col}});
    vector<vector<int>> vis(r,vector<int>(c,0));
    vector<vector<int>> dir(r,vector<int>(c,0));
    vector<vector<int>> dist(r,vector<int>(c,0));
    string dir_str="URDL";
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        int is_player = curr.first;
        int curr_row=curr.second.first;
        int curr_col=curr.second.second;
        //check if player reached at the end of the grid
        if(is_player && (curr_row==0||curr_row==r-1||curr_col==0||curr_col==c-1)){
            cout<<"YES"<<endl;
            cout<<dist[curr_row][curr_col]<<endl;
            string ans="";
            while(curr_row!=start_row || curr_col!=start_col){
                ans+=dir_str[dir[curr_row][curr_col]];
                int prev_row=curr_row-dr[dir[curr_row][curr_col]];
                int prev_col=curr_col-dc[dir[curr_row][curr_col]];
                curr_row=prev_row;
                curr_col=prev_col;
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
            return 0;
        }
        //move player to all the possible directions
        if(is_player){
            for(int i=0;i<4;i++){
                int new_row=curr_row+dr[i];
                int new_col=curr_col+dc[i];
                if(new_row>=0 && new_row<r && new_col>=0 && new_col<c && grid[new_row][new_col]!='#' && !vis[new_row][new_col] && grid[new_row][new_col]!='M' ){
                    vis[new_row][new_col]=1;
                    dist[new_row][new_col]=dist[curr_row][curr_col]+1;
                    dir[new_row][new_col]=i;
                    q.push({1,{new_row,new_col}});
                }
            }
        }
        //move monster to all possible direction
        else{
            for(int i=0;i<4;i++){
                int new_row=curr_row+dr[i];
                int new_col=curr_col+dc[i];
                if(new_row>=0 && new_row<r && new_col>=0 && new_col<c && grid[new_row][new_col]!='#' && !vis[new_row][new_col]){
                    vis[new_row][new_col]=1;
                    q.push({0,{new_row,new_col}});
                    grid[new_row][new_col]='#';
                }
            }
        }
        
    }
    cout<<"NO"<<endl;
    // vector<vector<pair<int,int> > > parent(r,vector<pair<int,int> >(c,{-1,-1}));


}