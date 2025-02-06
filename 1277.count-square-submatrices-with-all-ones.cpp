/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution
{
public:
    int rows=0;
    int columns=0;
    int re(int i, int j, int sz, vector<vector<int>> &matrix)
    {
        int count = 0;
         bool is_square = true;

        if (sz == 1)
        {
            return matrix[i][j];
        }
        int min_size = min(min(j+sz,columns),min(i+sz,rows));
        sz=min_size;
    
        for (int r = 0; r < matrix[0].size() - sz + 1; r++)
        {
            for (int c = 0; c < matrix.size() - sz + 1; c++)
            {
                for (int k = 0; k < sz; k++)
                {
                    for (int l = 0; l < sz; l++)
                    {
                        if (matrix[i + k][j + l] == 0)
                        {
                            is_square = false;
                            break;
                        }
                        if (!is_square)
                            break;
                    }
                }
                count += re(i, j, sz - 1, matrix);

            }
        }
        if (is_square)
                    return count + 1;
                else
                    return count;
    }

    int countSquares(vector<vector<int>> &matrix)
    {
        rows = matrix.size();
        columns = matrix[0].size();
        int sz = min(matrix.size(), matrix[0].size());

        return re(0, 0, sz, matrix);
    }
};
// @lc code=end
int main(){
    
}