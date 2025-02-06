/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int ac=a;
        int bc=b;
        int cc=c;
        string ans="";
        priority_queue<pair<int,char>> pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        while(pq.size()>1){
            char chr = pq.top().second;
            int chrcount = pq.top().first;
            if(ans.size()>=2 && ans[ans.size()-1]==chr && ans[ans.size()-2]==chr){
                auto top1 = pq.top();
                pq.pop();
                auto top2 = pq.top();
                pq.pop();
                ans += top2.second;
                if(top2.first > 1) {
                    top2.first--;
                    pq.push(top2);
                }
                pq.push(top1);
            }
            else{
                auto top = pq.top();
                pq.pop();
                ans += top.second;
                if(--top.first > 0) {
                    pq.push(top);
                }
        }
    }
    if(!pq.empty()){
        auto top = pq.top();
        while(top.first-- > 0 && !(ans.size() >= 2 && ans[ans.size()-1] == top.second && ans[ans.size()-2] == top.second)){
            ans += top.second;
        }
    }
    return ans;
}
};
// @lc code=end
// @lc code=end

