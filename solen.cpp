#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
void fileIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int k;
typedef vector<int> vi;
typedef pair<int,int> pii;

void buildobstacles(int x1,int y1,int x2,int y2,vector<vector<int>> &g,int n){
    for(int y=y1;y<=y2;y++){
        g[y][x1]++;
        if(x2<n)
            g[y][x2+1]--; 
    }
}
void addprefix(vector<vector<int>> &g,int row,int col){
    for(int i=0;i<col;i++){
        if(i==0) g[row][i] = g[row][i];
        else g[row][i] += g[row][i-1]; 
    }
}
int bfs(int m,int n,vector<vector<int>> &grid){
    queue<vi> q;
    if(grid[0][0] != 0 or grid[m-1][n-1] != 0) return 0;
    q.push({0,0,0});

    grid[0][0]=1;
    while(!q.empty()){
        auto t = q.front(); q.pop();
        int x = t[0], y=t[1], dist = t[2];
        //cout<<x<<" "<<y<<" "<<dist<<endl;
        if(x == m - 1 && y == n - 1) return dist;
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x < 0 or new_x >= m or new_y < 0 or new_y >= n) continue;
            if(grid[new_x][new_y] !=0 ) continue;
            q.push({new_x,new_y,dist+1});
            grid[new_x][new_y] = 1;
        }
    }
    return -1;
}

void solve(){
    int n,m;
    //m->row //n->col
    cin>>n>>m>>k;
    vi rect_x1(k,0) , rect_y1(k,0);
    vi rect_x2(k,0) , rect_y2(k,0);

    for(int i=0;i<k;i++)
        cin>>rect_x1[i];
    for(int i=0;i<k;i++)
        cin>>rect_y1[i];
    for(int i=0;i<k;i++)
        cin>>rect_x2[i];
    for(int i=0;i<k;i++)
        cin>>rect_y2[i];
    
    vector<vector<int>> g(m,vector<int> (n,0));
    //build obstacles
    for(int i=1;i<2;i++){
        int x1 = rect_x1[i], x2 = rect_x2[i];
        int y1 = rect_y1[i], y2 = rect_y2[i];
        buildobstacles(x1,y1,x2,y2,g,n);
    }
    // for(int i=0;i<m;i++){
    //     addprefix(g,i,n);
    // }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<bfs(m,n,g)<<endl;
}
int main(){
    fileIO();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}