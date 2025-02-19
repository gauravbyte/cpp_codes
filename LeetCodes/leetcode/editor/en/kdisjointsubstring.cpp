//
// Created by Gaurav Chaudhari on 16/02/25.
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isDisjoint(set<string>& set1, set<string>& set2) {
        for (auto it = set1.begin(); it != set1.end(); it++) {
            if (set2.find(*it) != set2.end()) {
                return false;
            }
        }
        return true;
    }
    bool maxSubstringLength(string s, int k) {
        //substring k disjoing special subtring
        //so for the given number
        map<char, int> mp;
        for (auto it = s.begin(); it != s.end(); it++) {
            mp[*it]++;
        }
        int count=0;
        for(int i = 0; i < len; i++) {
            for(int j = i ; j < len; j++) {
                mp[s[j]--;
                if(mp[s[j]] == 0){
                   count++;
                   break;
                }



            }
        }
    }
};

int main() {

}