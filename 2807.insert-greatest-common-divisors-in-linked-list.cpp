/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int m,int n){
        if(m>=n){
            if(m%n==0)
                return n;
            else{
                return gcd(n,m%n);
            }
        }
        else{
            return gcd(n,m);
        }
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur = head;
        while(cur->next!=NULL){
            int m = cur->val;
            int n = cur->next->val;
            ListNode *newNode = new ListNode;
            newNode->val=gcd(n,m);
            newNode->next = cur->next;
            cur->next=newNode;
            cur=newNode->next;
        }
        return head;
    }
};
// @lc code=end

