#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    // cin>>n;
    vector<int> arr={1, 4 ,5, 5, 6,6,7,8,9,10};
    int k=0;
    cout<<arr.size()<<endl;
    int up=upper_bound(arr.begin(), arr.end(), k)-arr.begin();
    int lb=lower_bound(arr.begin(), arr.end(), k)-arr.begin();
    cout<<"index range  is "<<lb<<" "<<up-1<<endl;
}