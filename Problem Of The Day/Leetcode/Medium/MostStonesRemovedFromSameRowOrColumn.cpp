// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

//DSU SOLUTION ==>
class Solution {
public:
    bool isValid(vector<int>&pos1, vector<int>&pos2)
    {
        if (pos1[0] == pos2[0]) return true;
        if (pos1[1] == pos2[1]) return true;
        return false;
    }
    int findParent(vector<int>&parent, int node)
    {
        while(parent[node] != node) { node = parent[node]; }
        return node;
    }
    void merge(vector<int>&parent, int& componentCount, int node1, int node2)
    {
        int parent1 = findParent(parent, node1);
        int parent2 = findParent(parent, node2);
        if (parent1 != parent2) 
        {
            componentCount--; //whenever we merge two components, totalComponentCount decrease by 1
            parent[parent1] = parent2; //or parent[parent2] = parent1 would also work :)
        }
    }
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        vector<int>parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        //==============================================
        int componentCount = n; //assuming "n" independent components at start
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isValid(stones[i], stones[j]))
                    merge(parent, componentCount, i, j);
            }
        }
        //===============================================
        return (n - componentCount); 
    }
};
//DFS SOLUTION ==>
class Solution {
public:
    bool isValid(vector<int>&pos1, vector<int>&pos2)
    {
        if (pos1[0] == pos2[0]) return true;
        if (pos1[1] == pos2[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>>&stones, vector<bool>&visited, int currIdx)
    {
        visited[currIdx] = true;
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i]) continue;
            if (isValid(stones[i], stones[currIdx]))  dfs(stones, visited, i);
        }
    }
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        vector<bool>visited(n, false);
        int componentCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;
            dfs(stones, visited, i);
            componentCount++;
        }
        return (n - componentCount); 
    }
};