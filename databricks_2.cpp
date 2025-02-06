/* Your task is the following: for each cyclic t-shift of nums1, calculate the sum of absolute differences with nums2. If the cyclic t-shift of nums1 is a new array numsShifted, the sum equals to

|numsShifted[0] - nums2[0]| + |numsShifted[1] - nums2[1]| + ... + |numsShifted[n - 1] - nums2[n - 1]|
Return a list of all the sums sorted in non-descending order as the answer.

Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than O(nums1.length3) will fit within the execution time limit.

Example

For nums1 = [1, 4, 2, 11] and nums2 = [10, 1, 8, 4], the output should be solution(nums1, nums2) = [7, 13, 25, 25].

Explanation:
Let's consider all possible cyclic t-shifts of nums1:

The 0-shift is [1, 4, 2, 11], and the sum of absolute differences with nums2 = [10, 1, 8, 4]:
= |1 - 10| + |4 - 1| + |2 - 8| + |11 - 4| = 9 + 3 + 6 + 7 = 25.
The 1-shift is [11, 1, 4, 2], and the sum of absolute differences with nums2 = [10, 1, 8, 4]:
= |11 - 10| + |1 - 1| + |4 - 8| + |2 - 4| = 1 + 0 + 4 + 2 = 7.
The 2-shift is [2, 11, 1, 4], and the sum of absolute differences with nums2 = [10, 1, 8, 4]:
= |2 - 10| + |11 - 1| + |1 - 8| + |4 - 4| = 8 + 10 + 7 + 0 = 25.
The 3-shift is [4, 2, 11, 1], and the sum of absolute differences with nums2 = [10, 1, 8, 4]:
= |4 - 10| + |2 - 1| + |11 - 8| + |1 - 4| = 6 + 1 + 3 + 3 = 13.
The non-descending list of all the sums is [7, 13, 25, 25], which is the answer.

Input/Output

[execution time limit] 0.5 seconds (cpp)

/* [memory limit] 1 GB

[input] array.integer nums1

An array of integers.

Guaranteed constraints:
1 ≤ nums1.length ≤ 100,
1 ≤ nums1[i] ≤ 1000.

[input] array.integer nums2

An array of integers.

Guaranteed constraints:
nums2.length = nums1.length,
1 ≤ nums2[i] ≤ 1000.

[output] array.integer

The list of all the sums of absolute differences, sorted in the non-descending order, which can be derived from nums2 and cyclic t-shifts of nums1, based on operations described above.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
string helloWorld(string name) {
    cout << "This prints to the console when you Run Tests" << endl;
    return "Hello, " + name;
} */
 #include<bits/stdc++.h>
 using namespace std;
 
 vector<int> solution(vector<int> nums1, vector<int> nums2) {
    //shift nums1;
    int n=nums1.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
        int temp=nums1[n-1];
        for(int j=n-1; j>0; j--){
            nums1[j]=nums1[j-1];
        }
        nums1[0]=temp;
        //calculate sum of absolute differences
        int sum=0;
        for(int k=0; k<n; k++){
            sum+=abs(nums1[k]-nums2[k]);
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
