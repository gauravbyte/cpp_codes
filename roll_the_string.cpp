#include<bits/stdc++.h>
using namespace std;
string roll_the_string(string s,vector<int> arr){
    string roll="";
    int n=s.size();
    vector<int> dp(n+1,0);
    for(int i=0;i<arr.size();i++){
        dp[arr[i]]++;
    }
    //suffix sum
    for(int i=n-1; i>=1; i--){
        dp[i]+=dp[i+1];
    }
    for(int i=1;i<=n;i++){
        int index=dp[i]%26;
        roll+=(s[i]-'a'+index)%26+'a';
    }
    return roll;
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<roll_the_string(s,arr)<<endl;
}