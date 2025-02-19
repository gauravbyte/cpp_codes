#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        const int MAX_VAL = 100000;
        // 1) Build an array that stores the smallest index j for each value in [1..MAX_VAL]
        //    If a value doesn't appear in 'elements', we keep it as -1.
        vector<int> minIdxOfValue(MAX_VAL + 1, -1);
        for (int j = 0; j < (int)elements.size(); j++) {
            int val = elements[j];
            if (minIdxOfValue[val] == -1 || j < minIdxOfValue[val]) {
                minIdxOfValue[val] = j;
            }
        }

        // 2) For each group, find the divisor that yields the smallest index j
        vector<int> result(groups.size(), -1);
        for (int i = 0; i < (int)groups.size(); i++) {
            int g = groups[i];
            int bestIndex = INT_MAX;

            // Iterate over divisors of g
            // For each divisor d, the pair is (d, g/d)
            for (int d = 1; d * d <= g; d++) {
                if (g % d == 0) {
                    // d is a divisor
                    int d1 = d;
                    int d2 = g / d;

                    // Check d1 if it exists in elements
                    if (d1 <= MAX_VAL) {
                        int idx = minIdxOfValue[d1];
                        if (idx != -1 && idx < bestIndex) {
                            bestIndex = idx;
                        }
                    }
                    // Check d2 if it exists in elements
                    // d2 might be equal to d1 if g is a perfect square, so check carefully
                    if (d2 <= MAX_VAL && d2 != d1) {
                        int idx = minIdxOfValue[d2];
                        if (idx != -1 && idx < bestIndex) {
                            bestIndex = idx;
                        }
                    }
                }
            }

            // If bestIndex is still INT_MAX, no divisor was found
            result[i] = (bestIndex == INT_MAX) ? -1 : bestIndex;
        }
        return result;
    }
};

int main(){
    // Example usage:
    vector<int> groups = {8, 4, 3, 2, 4};
    vector<int> elements = {4, 2};

    Solution sol;
    vector<int> assigned = sol.assignElements(groups, elements);

    // Print results
    for (int x : assigned) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}