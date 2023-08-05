// User function Template for C++
class Solution {
public:
    // straightforward BFS Approach with condition of revisit being
    // lesser cost path leads to revisiting node.

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // code here

        // adjacency vector
        vector<vector<int>> adj (N, vector<int>(N, -1));

        vector<int> cost(N, -1);

        for (auto i : edges) {
            int rt = i[0];
            int dest = i[1];
            int cst = i[2];

            adj[rt][dest] = cst;
            // adj[rt].push_back({dest, cst});
        }

        // gng for bfs

        queue<int> st;

        st.push(0);
        cost[0] = 0;

        while (!st.empty()) {
            int x = st.front();
            st.pop();
            for (int i = 0; i < N ; i++) {

                if (adj[x][i] != -1) {

                    if (cost[i] == -1) {
                        cost[i] = cost [x] + adj[x][i];
                        st.push(i);
                    }
                    else if (cost[i] > cost[x] + adj[x][i]) {
                        st.push(i);
                        // cout << x << " i " << i << " : bef " << cost[i] << " : aft " << cost[x] + adj[x][i] << "  " << cost [x] << " + " << adj[x][i] << endl;
                        cost[i] = cost[x] + adj[x][i];
                    }
                }
            }
        }

        return cost;

    }
};