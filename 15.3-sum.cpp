// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

    set<vector<int>> st;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int j=0;
    for (int i = 0; i < n-2; i++) {
        j=n-1;
        while(i<j-1){

            int search= -arr[i]-arr[j];
            //! find will give either 0 or 1
            auto it = lower_bound(arr.begin()+i+1,arr.begin()+j-1,search);
            if(it!=arr.end()){
                int third=*it;
                vector<int> triple={arr[i],arr[j],third};
                sort(triple.begin(),triple.end());
                st.insert(triple);
            }
            //write at decrement condition at the time of writing loop
            j--;
        }

    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    }
};
// @lc code=end

