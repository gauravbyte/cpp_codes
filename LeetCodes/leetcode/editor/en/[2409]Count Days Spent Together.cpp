
/**
Alice and Bob are traveling to Rome for separate business meetings. 

 You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. 
Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), 
while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each 
will be a 5-character string in the format "MM-DD", corresponding to the month 
and day of the date. 

 Return the total number of days that Alice and Bob are in Rome together. 

 You can assume that all dates occur in the same calendar year, which is not a 
leap year. Note that the number of days per month can be represented as: [31, 28,
 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]. 

 
 Example 1: 

 
Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", 
leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in 
Rome from August 16 to August 19. They are both in Rome together on August 16th, 
17th, and 18th, so the answer is 3.
 

 Example 2: 

 
Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", 
leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we 
return 0.
 

 
 Constraints: 

 
 All dates are provided in the format "MM-DD". 
 Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
 
 The given dates are valid dates of a non-leap year. 
 

 Related Topics Math String 👍 268 👎 588

*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
       int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
       vector<int> prefixMonth = {0};

       for(int i = 0; i < 12; i++) {
           prefixMonth.push_back(prefixMonth[i]+month[i]);
       }
       int startAlice = prefixMonth[stoi(arriveAlice.substr(0, 2))-1] + stoi(arriveAlice.substr(3,2));
       int endAlice = prefixMonth[stoi(leaveAlice.substr(0, 2))-1] + stoi(leaveAlice.substr(3,2));
       int startBob = prefixMonth[stoi(arriveBob.substr(0, 2))-1] + stoi(arriveBob.substr(3,2));
       int endBob = prefixMonth[stoi(leaveBob.substr(0, 2))-1] + stoi(leaveBob.substr(3,2));
        cout<< startAlice << " " << endAlice << endl;
        cout<< startBob << " " << endBob << endl;
       int range;
       int startOverlap = max(startAlice, startBob);
        int endOverlap = min(endAlice, endBob);

        return max(0, endOverlap - startOverlap+1);

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
std::string arriveAlice = "08-15";
    std::string leaveAlice = "08-18";
    std::string arriveBob = "08-16";
    std::string leaveBob = "08-19";
	Solution solution;
    solution.countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);
    return 0;
    

}
