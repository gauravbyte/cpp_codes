/* 
The doctor has S possible appointment slots, numbered from 1 to S. Each of
the patients has two preferences. Patient K would like to visit the doctor
during either slot A[K| or slot B[K]. The doctor can treat only one patient during
each slot.

Is it possible to assign every patient to one of their preferred slots so that
there will be at most one patient assigned to each slot?

Write a function:

bool solution (vector‹int> &A, vector<int> &B, int
5);

that, given two arrays A and B, both of N integers, and an integer S, returns
true if it is possible to assign every patient to one of their preferred slots, one
patient to one slot, and false otherwise.

Examples:

1. Given A = [1, 1, 3], B = [2, 2, 1] and S = 3, the function should return true. We
could assign patients in the following way: [1, 2, 3], where the K-th element of
the array represents the number of the slot to which patient K was assigned.
Another correct assignment would be [2, 1, 3]. On the other hand, [2, 2, 1]
would be an incorrect assignment as two patients would be assigned to slot 2.

2. Given A = [3, 2, 3, 1], B = [1, 3, 1, 2] and S = 3, the function should return
false. There are only three slots available, but there are four patients who
want to visit the doctor. It is therefore not possible to assign the patients to
the slots so that only one patient at a time would visit the doctor.

3. Given A = [2, 5, 6, 5], B = [5, 4, 2, 2) and S = 8, the function should return
true. For example, we could assign patients in the following way: [5, 4, 6, 2].

4. Given A = [1, 2, 1, 6, 8, 7, 8], B = [2, 3, 4, 7, 7, 8, 71 and S = 10, the function
should return false. It is not possible to assign all of the patients to one of
their preferred slots so that only one patient will visit the doctor during one
slot.

 */

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
bool backtrack(vector<int> &A, vector<int> &B, int S, int i, vector<int> &slots){
    if(i == A.size()) return true;
    for(int j=0;j<slots.size();j++){
        if(slots[j] == 0){
            if(slots[j] == A[i] or slots[j] == B[i]){
                slots[j] = i+1;
                if(backtrack(A,B,S,i+1,slots)) return true;
                slots[j] = 0;
            }
        }
    }
    return false;
}



bool solution(vector<int> &A, vector<int> &B, int S) {
    // Implement your solution here
    //solve via backtracking
    //check if the number of slots is greater than the number of patients
    int n=A.size();
    vector<int> slots(n+1,0);
    if(S < n) return false;
    for(int i=0;i<n;i++){
        if(A[i] == B[i]) slots[A[i]] = i+1;
    }
    backtrack(A,B,S,0,slots);
    return true;

    
    
}

