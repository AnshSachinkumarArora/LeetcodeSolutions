
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
  int findDistinctIslandsDFS(vector<vector<int>> &matrix)
  {
    // TODO: Write your code here
    unordered_set<string> set;
    for(int i = 0; i < matrix.size(); i++) {
      for(int j = 0; j < matrix[0].size(); j++) {
        if(matrix[i][j] == 1) {
          string pattern = "";
          dfs(i, j, pattern, matrix, "O");
          cout<<pattern<<endl;
          set.insert(pattern);
        }
      }
    }
    return set.size();
  }

  void dfs(int i, int j, string &pattern, vector<vector<int>> &matrix, string direction) {
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
      return;
    }
    if (matrix[i][j] == 0) return;
    matrix[i][j] = 0;
    pattern += direction;
    dfs(i, j-1, pattern, matrix, "L");
    dfs(i, j+1, pattern, matrix, "R");
    dfs(i-1, j, pattern, matrix, "U");
    dfs(i+1, j, pattern, matrix, "D");
  }
};

