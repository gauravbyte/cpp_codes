/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class MedianFinder {
public:
        priority_queue<int, vector<int>, less<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int count=0;
        int median=-1;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }

        count++;
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
        

    }
    
    double findMedian() {

        10101110110
        
        if(count%2==0){
            return (left.top()+right.top())/2.0;
        }
        else{
            return left.top()*1.0;
        }


    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

