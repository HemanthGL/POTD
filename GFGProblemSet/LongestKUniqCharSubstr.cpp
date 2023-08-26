//User function template for C++

class Solution {
public:

    // Problemset: Longest k Unique Characters Substring
    //          Return the length of longest substring containing K no. of unique characters

    // Problemset Link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

    // Approach: Maintain an Unordered Map to have count/frequency of each unique character.
    //          Whenever the count of unique characters exceeds K, start increasing the left pointer from the left end, until the no. of unique character decreases to K again.
    //              Like this maintain the temp, and max of length of the current substring, return the max length as returnvalue.

    // SOLUTION METRICS:
    //      TC: O(N)
    //      SC: O(N) -> For Unordered Map
    int longestKSubstr(string s, int k) {
        // your code here
        int left = 0, right = 0, n = s.length();
        unordered_map<char, int> mp;

        int ctrl = 0, mx = -1, tmp = 0;
        while (right != n && left != n) {

            // if (left > right)
            //     break;

            if (mp.find(s[right]) == mp.end()) {
                mp[s[right]] = 1;
                ctrl++;
            }
            else
                mp[s[right]] += 1;

            if (ctrl <= k) {
                if (ctrl == k) {
                    tmp = right - left + 1;
                    mx = max(mx, tmp);

                }
            }
            // ctrl++;
            right++;
            if (ctrl > k) {
                while (mp.size() > k) {
                    mp[s[left]] -= 1;
                    if (mp[s[left]] == 0) {
                        mp.erase(s[left]);
                        ctrl--;
                    }
                    left++;
                }
                // ctrl--;
            }
            // cout << right << " " << mx << " l " << left << " r " << right << " " << ctrl << endl;

        }

        return mx;
    }
};