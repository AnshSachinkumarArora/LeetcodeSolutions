using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
  int countIslands(vector<vector<int>> &matrix)
  {
    int totalIslands = 0;
    // TODO: Write your code here
    for(int i = 0; i < matrix.size(); i++) {
      for(int j = 0; j < matrix[0].size(); j++) {
        if(matrix[i][j] == 1) {
          totalIslands++;
          dfs(i, j, matrix); 
        }
      }
    }
    return totalIslands;
  }

  void dfs(int i, int j, vector<vector<int>> &matrix) {
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
      return;
    }
    if (matrix[i][j] == 0) return;
    matrix[i][j] = 0;
    dfs(i, j-1, matrix);
    dfs(i, j+1, matrix);
    dfs(i-1, j, matrix);
    dfs(i+1, j, matrix);
  }
};

