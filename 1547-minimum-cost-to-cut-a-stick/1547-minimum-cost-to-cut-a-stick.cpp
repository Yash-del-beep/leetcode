class Solution {
public:
    int solve(vector<int>& cuts, int s, int e, vector<vector<int>>& dp) {
        
        // No cut possible between s and e
        if (e - s < 2)
            return 0;

        // Already calculated
        if (dp[s][e] != -1)
            return dp[s][e];

        int mini = INT_MAX;

        // Try every possible cut
        for (int i = s + 1; i < e; i++) {

            int cost = cuts[e] - cuts[s]
                       + solve(cuts, s, i, dp)
                       + solve(cuts, i, e, dp);

            mini = min(mini, cost);
        }

        return dp[s][e] = mini;
    }

    int minCost(int n, vector<int>& cuts) {

        // Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort cuts
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(cuts, 0, m - 1, dp);
    }
};