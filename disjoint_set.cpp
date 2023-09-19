#include<bits/stdc++.h>
using namespace std;

class Disjoint_set {
    vector<int> rank, parent;
public:
    // Correct constructor name and initialization
    Disjoint_set(int n) : rank(n, 0), parent(n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node]); // added return
    }
    void union_by_rank(int u, int v) {
        int rootU = find_parent(u);
        int rootV = find_parent(v);
        
        if(rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if(rank[rootV] > rank[rootU]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    void print_rank_and_parent() {
        for(int i = 0; i < parent.size(); i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < rank.size(); i++) {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n = 5;
    Disjoint_set ds(n); // Use the proper constructor
    ds.union_by_rank(0, 2);
    ds.union_by_rank(4, 2);
    ds.union_by_rank(3, 1);
    ds.print_rank_and_parent();
    if(ds.find_parent(4) == ds.find_parent(0)){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
