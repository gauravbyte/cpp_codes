
/**
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-
DD, return the day number of the year. 

 
 Example 1: 

 
Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
 

 Example 2: 

 
Input: date = "2019-02-10"
Output: 41
 

 
 Constraints: 

 
 date.length == 10 
 date[4] == date[7] == '-', and all other date[i]'s are digits 
 date represents a calendar date between Jan 1ˢᵗ, 1900 and Dec 31ˢᵗ, 2019. 
 

 Related Topics Math String 👍 472 👎 482

*/


#include<bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int res = 0;
        for (int i = 1; i < month; i++) {
            res += days[i];
        }
        res += day;
        if (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
            res++;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    Solution s;
    

}
