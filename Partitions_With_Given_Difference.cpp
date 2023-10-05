#include <bits/stdc++.h> 

int countPartitions(int n, int d, vector<int> &arr) {
    // Calculate the sum of all elements in the array
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(arr[i] == 0) count++;
    }
    
    // Handle the case when array contains 0
    if((sum + d) % 2 != 0) return 0;
    if(count > 0) return pow(2, count);
    
    // Calculate the target sum for each partition
    int targetSum = (sum + d) / 2;
    
    // Initialize the dp array
    int dp[n + 1][targetSum + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= targetSum; j++){
            // Base case: when either the array or the target sum is empty, there is only one way to partition
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }
    
    // Fill the dp array
    for(int i = 1; i <= n; i++){
        for(int currentSum = 1; currentSum <= targetSum; currentSum++){
            if(arr[i - 1] <= currentSum){
                dp[i][currentSum] = dp[i - 1][currentSum - arr[i - 1]] + dp[i - 1][currentSum];
            }
            else dp[i][currentSum] = dp[i - 1][currentSum];
        }
    }
    
    // Return the number of partitions that add up to the target sum
    return dp[n][targetSum];
}