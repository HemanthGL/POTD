// User function Template for C++

class Solution {
public:
    // straight forward BFS approach to trace out all the shortest paths to all coordinates
    // starting from the destination A[X][Y]

    // printing the dist to A[0][0] (if reachable);

    // Questions Link: https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

    void pushOthers(queue<pair<int, int>> &st, int& x, int& y, vector<vector<int>> &A, vector<vector<int>> &mat) {
        int row = A.size();
        int col = A[0].size();
        int val = mat[x][y] + 1;

        if (x - 1 >= 0) {
            if (A[x - 1][y] != 0 && mat[x - 1][y] > val) {
                mat[x - 1][y] = val;
                st.push({x - 1, y});
            }
        }
        if (x + 1 < row) {
            if (A[x + 1][y] != 0 && mat[x + 1][y] > val) {
                mat[x + 1][y] = val;
                st.push({x + 1, y});
            }
        }
        if (y + 1 < col) {
            if (A[x][y + 1] != 0 && mat[x][y + 1] > val) {
                mat[x][y + 1] = val;
                st.push({x, y + 1});
            }
        }
        if (y - 1 >= 0) {
            if (A[x][y - 1] != 0 && mat[x][y - 1] > val) {
                mat[x][y - 1] = val;
                st.push({x, y - 1});
            }
        }
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int& X, int& Y) {
        if (A[0][0] == 0 || A[X][Y] == 0)
            return -1;
        vector<vector<int>> mat(N, vector<int> (M, M * N + 1));
        mat[X][Y] = 0;
        queue<pair<int, int>> st;
        st.push({X, Y});
        while (!st.empty()) {
            int x = st.front().first;
            int y = st.front().second;
            pushOthers(st, x, y, A, mat);
            st.pop();

        }
        return (mat[0][0] == M * N + 1 ? -1 : mat[0][0]);
    }
};