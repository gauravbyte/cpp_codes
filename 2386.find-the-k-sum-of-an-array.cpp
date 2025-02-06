/*
 * @lc app=leetcode id=2386 lang=cpp
 *
 * [2386] Find the K-Sum of an Array
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        //positive number heap
        priority_queue<int,vector<int>,greater<int>>pos_pq;
        //negative number heap
        priority_queue<int,vector<int>,less<int>>neg_pq;
        //store the sum of all +ve numbers
        long long sum=0;
        for(auto x:nums){
            if(x>0){
                pos_pq.push(x);
                sum+=x;
            }
            else{
                neg_pq.push(x);
            }
        }
        int pos,neg;
        while(k>0&& pos_pq.size()&&neg_pq.size()){
            //print all variables status


            pos=pos_pq.top();
            neg=neg_pq.top();
            cout<<"pos_pq.size()="<<pos_pq.size()<<endl;
            cout<<"neg_pq.size()="<<neg_pq.size()<<endl;
            cout<<"k="<<k<<endl;
            cout<<"sum="<<sum<<endl;
            cout<<"pos="<<pos<<endl;
            cout<<"neg="<<neg<<endl;
            if(pos==abs(neg)){
                sum-=pos;
                pos_pq.pop();
                neg_pq.pop();
                k-=2;
            }
            else if(pos<abs(neg)){
                sum-=pos;
                pos_pq.pop();
                k--;
            }
            else{
                sum+=neg;
                neg_pq.pop();
                k--;
            }
        }
        while(k>0&& pos_pq.size()){
            pos=pos_pq.top();
            cout<<"pos_pq.size()="<<pos_pq.size()<<endl;
            cout<<"neg_pq.size()="<<neg_pq.size()<<endl;
            cout<<"k="<<k<<endl;
            cout<<"sum="<<sum<<endl;
            cout<<"pos="<<pos<<endl;
            sum-=pos;
            pos_pq.pop();
            k--;
        }
        while(k>0&& neg_pq.size()){
            cout<<"pos_pq.size()="<<pos_pq.size()<<endl;
            cout<<"neg_pq.size()="<<neg_pq.size()<<endl;
            cout<<"k="<<k<<endl;
            cout<<"sum="<<sum<<endl;
            cout<<"neg="<<neg<<endl;
            neg=neg_pq.top();
            sum+=neg;
            neg_pq.pop();
            k--;
        }

        return sum; 

    }
};
// @lc code=end

