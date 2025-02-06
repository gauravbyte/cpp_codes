#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

int directionX[4] = {-1,0,1,0};
int directionY[4] = {0,1,0,-1};

void buildWalls(int startX,int startY,int endX,int endY,vector<vector<int>> &matrix,int matrixSize){
    for(int y=startY;y<=endY;y++){
     for(int x = startX;x<= endX;x++){
         matrix[y][x] = 0;
     }
    }
}

bool isOutOfBounds(int newX,int newY,int rows, int cols){
    if(newX < 0 or newX >= rows or newY < 0 or newY >= cols) return true;
    else return false;
}

int breadthFirstSearch(int rows,int cols,vector<vector<int>> &matrix){
    queue<vector<int>> q;
    if(matrix[0][0] == 0 or matrix[rows-1][cols-1] == 0) return 0;
    q.push({0,0,0});
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    while(!q.empty()){
        auto current = q.front(); q.pop();
        int lastRow =rows-1;
        int lastCol = cols-1;
        int x = current[0], y=current[1], distance = current[2];
        if(x == lastRow && y == lastCol) return distance;
        for(int i=0;i<4;i++){
            int newX = x + directionX[i];
            int newY = y + directionY[i];
            if(isOutOfBounds(newX,newY,rows,cols)) continue;
            if(matrix[newX][newY] == 0 or visited[newX][newY] ) continue;
            q.push({newX,newY,distance+1});
            visited[newX][newY] = true;
        }
    }
    return -1;
}

int solution(int N, int M, vector<int> &startX, vector<int> &startY, vector<int> &endX, vector<int> &endY) {
    vector<vector<int>> matrix(M,vector<int> (N,1));
    unordered_set <vector<int>> s;

    for(int i=0;i<startX.size();i++){
        int x1 = startX[i];
        int x2 = endX[i];
        int y1 = startY[i];
        int y2 = endY[i];
        // buildWalls(x1,y1,x2,y2,matrix,N);
        if(s.find({x1,y1,x2,y2}) != s.end()) continue;
        for(int y=y1;y<=y2;y++){
            for(int x = x1;x<= x2;x++){
                matrix[y][x] = 0;
            }
        }
    }
    
    int result = breadthFirstSearch(M,N,matrix);
    return result ;
}