/* Write an algorithm for the transmitter to identify the total number of
completed iterations.
Input
The input consists of a string - receivedSignalB, representing the transmitted
signal which was received by tower B (N).
Output
Print an integer representing the total number of completed iterations.
Note
receivedSignalB consists of Os and 1s only.
A subsequence of 01 is of length two where the first character is 0 and the
second character is 1.
Example
Input:
0110110
Output:
1
Explanation:
The transmitted signal received by tower B: 0110110
1st Iteration:
Filter 1 removes the subsequence from (1,2) position. Therefore, N becomes:
10110
Filter 2 removes the subsequence from (2,3) position. Therefore, N becomes:
110
Therefore, 1 iteration completed
2nd Iteration:
Since now the updated transmitted signal is: 110, filter 1 cannot remove the
subsequence 01. Therefore, the cleaning process ends here.
Therefore, the final output is: 1 */


#include<bits/stdc++.h>
using namespace std; 
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int count=0;
    
}