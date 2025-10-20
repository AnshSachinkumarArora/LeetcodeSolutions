#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the province count.
    int findProvinces(vector<vector<int>>& isConnected) {
        // ToDo: Write Your Code Here.
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;
        for(int i = 0; i < visited.size(); i++) {
            if(!visited[i]) {
                provinces++;
                cout<<i<<endl;
                dfs(i, visited, isConnected);
            }
        }
        return provinces;
    }

    void dfs(int start, vector<bool>& visited, const vector<vector<int>>& graph) {
        visited[start] = true;
        for(int i = 0; i < graph[start].size(); i++) {
            int n = graph[start][i];
            if(n == 1 && !visited[i] && i != start) {
                dfs(i, visited, graph);
            }
        }
    }
};

