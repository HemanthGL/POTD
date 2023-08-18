class Solution {
public:
    // Brute : Try to count all the Edges and subtract the repeating common edge.
    // Do this for all pairs of nodes in the graph, and maintain the max count of edges for pair of nodes.

    // To be Explored: More Optimized Approach & Solution.

    // Problemset Link: https://leetcode.com/problems/maximal-network-rank/description/
    // Problem CODE: 1615

    // DIFFICULTY: MEDIUM

    // SOLUTION METRICS:
    //      TIME COMPLEXITY:     O (N^2)
    //      SPACE COMPLEXITY:    O (N^2) -> Adjacency List Constructed.

    /* TOPICS:
            Basic Graph Theory

    */

    int findCount(vector<vector<int>> &roads, int i, int j) {
        int ans = 0;
        ans += roads[i].size() + roads[j].size();

        if (find(roads[i].begin(), roads[i].end(), j) != roads[i].end())
            ans -= 1;

        return ans;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>());

        // create adjacency list:
        for (auto i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }


        int mx = INT_MIN;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if (i == j) continue;
                int tmp = findCount(adj, i, j);
                mx = max(mx, tmp);
                // cout << i << " " << j << " " << mx << endl;
            }
        }
        return mx;
    }
};