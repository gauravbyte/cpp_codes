class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[201][201] = {INT_MAX};
        //! all values are not initalized to int_max only some values are intitalized
            for (int i = 0; i < 201; ++i) {
            for (int j = 0; j < 201; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = triangle[0][0];//traingle
        int sum=0; 
        for(int i=0; i<n; i++){
            sum += triangle[i][0];
            dp[i][0] = sum;
        }
        //!check if n is greater than 1 to get this value
        if(n>1)
        dp[1][1] = dp[0][0] + triangle[1][1];
        for(int i=2; i<n; i++){-
            for(int j=1;j<=i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        int minsm = INT_MAX;
        for(int i=0; i<n; i++){
            minsm = min(minsm,dp[n-1][i]);
        }
        
        return minsm;
    }
};