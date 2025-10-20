#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        // ToDo: Write Your Code Here.
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);  // Undirected graph
        }
        return recurse(visited, start, end, graph);
    }

    bool recurse(vector<bool> visited, int start, int end, vector<vector<int>>& edges) {
        visited[start] = true;
        if(start == end) {
            return true;
        }
        for(auto neighbours : edges[start]) {
            if(!visited[neighbours] && recurse(visited, neighbours, end, edges)) {
                return true;
            }
        }
        return false;
    }
};
