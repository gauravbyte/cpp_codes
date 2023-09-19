#include<bits/stdc++.h>
using namespace std;
class Union_find{

    public:
    vector<int> size;
    vector<int> parent;
    Union_find(int n){
        // vector<int> size(n+1,1);  !!!!!!!!This is wrong!!!!!!! because 
        //! you can't redeclare the array you have to resize
        // vector<int> parent(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=1; i<=n; i++){
            parent[i]=i;
        }
    }
    int find_parent(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find_parent(parent[x]);
    }
    void union_set(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b){
            if(size[a]>size[b]){
                parent[b] = a;
                size[a] += size[b];
            }
            else{
                parent[a] = b;
                size[b] += size[a];
            }
        }


    }
    void print_parent(){
        for(int i=1; i<parent.size(); i++){
            cout<<parent[i]<<" ";
        }
    }

};
int main(){
    int m,n;
    cin>>n>>m;
    Union_find uf(n);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        uf.union_set(a,b);
    }
    int count=0;
    set <int> st;
    for(int i=1; i<=n; i++){
        st.insert(uf.find_parent(i));
    }
    count=st.size();
    // cout<<count;//count should return edges required to connect all the nodes
    cout<<count-1<<endl;
    int start=*st.begin();
    auto i=st.begin();
    i++;
    for(; i!=st.end(); i++){
        cout<<start<<" "<<*i<<endl;
        start=*i;
    }
    return 0;
}