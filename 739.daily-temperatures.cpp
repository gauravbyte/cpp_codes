// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem739.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int pi=0,n=temperatures.size();
        vector<int>arr(n,0);
        for(int i=0; i<n-1; i++){
            int ct = temperatures[i];
            int nxt = temperatures[i+1];
            if(ct>nxt){
                st.push(i);
            }
            else{
                arr[i]=1;
                while(!st.empty() && st.top()<nxt){
                    arr[st.top()] = i-st.top()+1;
                    st.pop();
                }
            }
            
        }
        while(!st.empty()){
            arr[st.top()]=0;
            st.pop();
        }
        return arr;
    }
};
// @lc code=end

