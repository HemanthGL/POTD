class Solution {
public:

    // Problem Stmt: Maximum Length of Pair Chain

    // Problemset Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

    // Approach: Sort the pair of Chains according to the end values of each chain. [ Write the custom comparator function for this. ]
    //      Later just iterate on this sorted pairs and add up the count for each separated chain, comparing prev ending chain value with starting chain value of the next chain.

    // SOLUTION METRICS:
    //      TC: O( NlogN + N ) => O(NlogN)
    //      SC: O(N) => [ Stack space for custom comparator function ]


    static bool comp(vector<int> a, vector<int> b) {
        return (a[1] < b[1]) ? true : false ;
    }
    int findLongestChain(vector<vector<int>>& pairs) {

        // sort of like Schedule Meetings question

        // sort pairs based upon ending values
        // iterate upon pairs on the ending values by comparing end < start

        // write custom comparator function

        sort(pairs.begin(), pairs.end(), comp);

        for (auto i : pairs) {
            for (auto j : i) {
                cout << j << " " ;
            }
            cout << endl;
        }
        int startend = 0;
        int nextst = 1;

        int cnt = 1;

        while (nextst < pairs.size()) {
            if (pairs[nextst][0] > pairs[startend][1]) {
                startend = nextst;
                nextst += 1;
                cnt++;
            }
            else
                nextst++;
        }

        return cnt;

    }
};