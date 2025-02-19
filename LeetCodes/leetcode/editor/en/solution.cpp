#include <bits/stdc++.h>
using namespace std;

/**
 * Recursively computes the maximum sum of medians using the first i elements
 * of the sorted array A.  Uses memoization to avoid repeated calculations.
 */
long long dfs(int i, const vector<long long>& A, vector<long long>& memo) {
    // Base case: if i < 3, can't form any cluster of 3
    if (i < 3) return 0;

    // If already computed, return it
    if (memo[i] != -1) {
        return memo[i];
    }

    // Option 1: Skip the i-th element (index i-1) => f(i-1)
    long long optionSkip = dfs(i - 1, A, memo);

    // Option 2: Form a cluster with the last three elements => median is A[i-2]
    // Then add that to f(i-3)
    long long optionTake = A[i - 2] + dfs(i - 3, A, memo);

    // Take the maximum of the two choices
    long long best = max(optionSkip, optionTake);
    memo[i] = best;
    return best;
}

/**
 * Returns the maximum sum of medians of any set of clusters of size 3
 * formed from the given list host_throughput.
 */
long long getMaxThroughput(vector<long long> host_throughput) {
    // 1) Sort the array
    sort(host_throughput.begin(), host_throughput.end());
    int n = (int)host_throughput.size();

    // 2) Create a memo array for f(i), where 0 <= i <= n
    vector<long long> memo(n + 1, -1);

    // 3) We'll define a small helper base for the first 3 states:
    //    f(0) = f(1) = f(2) = 0
    memo[0] = 0;
    if (n >= 1) memo[1] = 0;
    if (n >= 2) memo[2] = 0;

    // 4) Recursively get f(n)
    return dfs(n, host_throughput, memo);
}

int main() {


    // 2) Read the throughput array
    vector<long long> host_throughput(n);
    for (int i = 0; i < n; i++) {
        cin >> host_throughput[i];
    }

    // 3) Compute the result
    long long result = getMaxThroughput(host_throughput);

    // 4) Print the result
    cout << result << "\n";

    // --------------------------
    // Sample test:
    // Input:
    //  6
    //  4
    //  6
    //  3
    //  5
    //  4
    //  5
    // Expected Output: 9
    // (Because sorting => [3,4,4,5,5,6], we can form two clusters with medians 5 and 4 => 9)

    return 0;
}