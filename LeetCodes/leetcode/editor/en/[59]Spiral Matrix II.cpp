
/**
Given a positive integer n, generate an n x n matrix filled with elements from 1
 to n² in spiral order.


 Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]


 Example 2:


Input: n = 1
Output: [[1]]



 Constraints:


 1 <= n <= 20


 Related Topics Array Matrix Simulation 👍 6558 👎 269

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int row = 0, col = 0;
    int value = 1;
    int range = n;

    while (range > 0) {
      if (range == 1) { // Handle center element for odd n
        matrix[row][col] = value;
        break;
      }

      for (int i = 0; i < range - 1; i++)
        matrix[row][col++] = value++; // Move Right
      for (int i = 0; i < range - 1; i++)
        matrix[row++][col] = value++; // Move Down
      for (int i = 0; i < range - 1; i++)
        matrix[row][col--] = value++; // Move Left
      for (int i = 0; i < range - 1; i++)
        matrix[row--][col] = value++; // Move Up

      row++;
      col++;      // Move to the next inner layer
      range -= 2; // Reduce the range for the next spiral loop
    }

    return matrix;
  }
};

// Function to print matrix

// leetcode submit region end(Prohibit modification and deletion)
