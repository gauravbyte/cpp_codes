/* Time limit: 1.00 s Memory limit: 512 MB
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input

The first input line has two integers n
 and m
: the height and width of the map.

After this there are n
 lines of m
 characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

Output

First print "YES" if your goal is possible, and "NO" otherwise.

If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R). You can print any path, as long as its length is at most n⋅m
 steps.

Constraints
1≤n,m≤1000

Example

Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>n>>m;
    //vector<vector<int> > mz(n,vector<int>(m,0));
    vector<vector<char> > mz(n,vector<char>(m,'0');
    vector<pair<int,int> > mnstr;
    int str,stc,k;
    set <pair<int,int> > endp;
    queue<pair<int,pair<int,int> > > q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>k;
            k = mz[i][j];
            if(mz[i][j] =='M') mnstr.push_back({i,j});
            else if(k=='A') {str=i; stc=j;}
            //!j=0||i==n-1||j==m-1){ equal to sign
            //* put this in the bfs section
            // else if(i==0||j==0||i==n-1||j==m-1){
            //     //! if(mz[i][j]==".")endp.insert({i,j});
            //     //!not working if(mz[i][j]==''.')endp.insert({i,j});
               
            // }

        }
    }
    q.push( {0, {str,stc}});
    for( auto [r,c]: mnstr){
        q.push({1,{r,c}});
    }
    vector<vector<int> > predr(n,vector<int>(m,-1));
    string dir = "URDL";
    //! int dr = {-1,0,1,0};
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!q.empty()){
        int state= q.front().first;
        int cr = q.front().second.first;
        int cc = q.front().second.second;
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc+dc[i];
            if(0<=nr && nr < n && 0<=nc && nc <m){
                if(state==0){
                    predr[nr][nc] = i;
                    if(mz[nr][nc]=='M'||mz[nr][nc]=='#') continue;
                    else if(0==nr || nr == n-1 || 0==nc || nc==m-1 ){
                        //got the path print with the help of parent array
                    }
                    else{
                        q.push({0,{nr,nc}});
                    }
                }

            }

        }
    }
}