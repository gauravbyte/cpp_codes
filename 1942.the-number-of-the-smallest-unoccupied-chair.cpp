/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {  
public:  
    int smallestChair(vector<vector<int>>& times, int targetFriend) {  
        int t_arrival = times[targetFriend][0];  
        // Sort times based on arrival times  
        sort(times.begin(), times.end());   
        // Min-heap to track departure times and chair indices  
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minhp;  
        // Set to track available chair indices  
        set<int> avail;  

        // Initialize available chairs  
        for (int i = 0; i < times.size(); ++i) {  
            avail.insert(i);  
        }  
        
        int nextSeat = 0;  
        
        // Process each friend's arrival and departure times  
        for (auto &t : times) {  
            int at = t[0];  
            int dt = t[1];  
            
            // Free up chairs whose friends have already left  
            while (!minhp.empty() && minhp.top().first <= at) {  
                avail.insert(minhp.top().second);  
                minhp.pop();  
            }  
            
            // Allocate smallest available chair  
            int chair = *avail.begin();  
            if (t_arrival == at) {  
                return chair;  
            }  
            avail.erase(avail.begin());  
            minhp.push({dt, chair});  
        }  
        
        return -1; // Should not reach here based on problem constraints  
    }  
};
// @lc code=end

